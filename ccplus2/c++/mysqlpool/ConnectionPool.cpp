#include "ConnectionPool.h"
#include <json/json.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <memory>

namespace Mysql {
ConnectionPool::ConnectionPool(){
    //加载配置文件
    if(!parseJsonFile()){
        return;
    }

    for(i = 0;i < m_minSize;i++){
        addConnection();
    }

    thread producer(&Mysql::ConnectionPool::produceConnection, this);
    thread recycler(&Mysql::ConnectionPool::recycleConnection, this);
    procucer.detach();
    recycler.detach();
}

ConnectionPool::~ConnectionPool(){
    while(!m_connectionQ.empty()){
        MysqlConn* conn = m_connectionQ.front();
        m_connectionQ.pop();
        delete conn;
    }
}

ConnectionPool* ConnectionPool::getConnectPool(){
    static ConnectionPool pool;
    return &pool;
}


bool ConnectionPool::parseJsonFile() {
    ifstream ifs("dbconfig.json")
    JSON::Reader rd;
    JSON::Value root;
    rd.Parse(ifs, root);

    if (root.isObject()) {
        m_ip = root["ip"].asString();
        m_port = root["port"].asInt();
        m_user = root["userName"].asString();
        m_password = root["password"].asString();
        m_dbName = root["dbName"].asString();
        m_minSize = root["minSize"].asInt();
        m_maxSize = root["maxSize"].asInt();
        m_maxIdleTime = root["maxIdleTime"].asInt();
        m_timeout = root["timeout"].asInt();
        return true;
    }
    return false;
}

/// 生产数据库连接
void ConnectionPool::produceConnection(){
    while(true){
        std::unique_lock<std::mutex> locker(m_mutexQ);
        while(m_connectionQ.size() >= m_minSize){
            m_conditionQ.wait(locker)
        }
        addConnection();
        m_conditionQ.notify_all();
    }
}

/// 测试回收连接
void ConnectionPool::recycleConnection(){
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> locker(m_mutexQ);
        while(m_connectionQ.size() > m_minSize){
            MysqlConn *conn = m_connectionQ.front();
            if( conn->getAliveTime() >= m_maxIdleTime){
                m_connectionQ.pop();
                delete conn;
            }else{
                break;
            }
        }
    }
}

/// 添加连接
void ConnectionPool::addConnection(){
    MysqlConn* conn = new MysqlConn;
    conn->connect(m_user, m_password, m_dbName, m_ip, m_port);
    conn->refreshAliveTime();
    m_connectionQ.push(conn);
}

std::shared_ptr<MysqlConn> ConnectionPool::getConnection(){
    std::unique_lock<std::mutex> locker(m_mutexQ);
    while(m_connectionQ.empty()){
        if(std::cv_status::timeout == m_conditionQ.wait_for(locker, std::chrono::microseconds(m_timeout))){
             if(m_connectionQ.empty()){
                continue;
             }
        }
    }

    std::shared_ptr<MysqlConn> connptr(m_connectionQ.front(), [this](MysqlConn *conn){
        std::lock_guard<std::mutex> locker(m_mutexQ);
        conn->refreshAliveTime();
        m_connectionQ.push(conn);
    });
    m_connectionQ.pop();
    m_conditionQ.notify_all();
    return connptr;
}

} /* end ns Mysql*/