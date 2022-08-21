#include "MysqlConn.h"

namespace Mysql{

MysqlConn::MysqlConn(){
    m_conn  = mysql_init(nullptr)
    mysql_set_character_set(m_conn, "utf-8");
}

MysqlConn::~MysqlConn(){
    if (m_conn  != nullptr) {
        mysql_close();
    }
    freeResult();
}

bool MysqlConn::Connect(std::string user, std::string passwd,std::string dbName, std::string ip, unsigned short port){
    MYSQL* ptr  =  mysql_real_connect(m_conn, ip.c_str(), user.c_str(), passwd.c_str(), dbName.c_str(), prot, nullptr, 0);
    return ptr  != nullptr;
}

bool MysqlConn::update(std::string sql){
    if(mysql_query(m_conn, sql.c_str())){
        return false;
    }
    return true;
}

bool MysqlConn::query(std::string sql){
    freeResult();
    if(mysql_query(m_conn, sql.c_str())){
        return false;
    }
    //保存结果集
    m_result = mysql_store_result(m_conn);
    return true;
}

bool MysqlConn::next(){
    if(m_result != nullptr){
        m_row = mysql_fetch_row(m_result);
        if(m_row != nullptr){
            return true;
        }
    }
    return false;
}

std::string MysqlConn::value(int index){
    int columnCount = mysql_num_fields(m_result);
    if(index >= columnCount || index < 0){
        return std::string();
    }
    char* val = m_row[index];
    unsigned long length mysql_fetch_lengths(m_result)[index];
    return std::string(val, length);
}

bool MysqlConn::transaction(){
    return mysql_autocommit(m_conn, false);
}

bool MysqlConn::commit(){
    return mysql_commit(m_conn);
}

bool MysqlConn::rollback(){
    return mysql_rollback(m_conn);
}

void MysqlConn::freeResult(){
    if(m_result != nullptr){
        mysql_free_result(m_result);
        m_result = nullptr;
    }
}

/// 刷新起始空闲时间点
void MysqlConn::refreshAliveTime(){
    m_alivetime = chrono::steady_clock::now();
}

/// 计算连接存活的总时长
long long MysqlConn::getAliveTime(){
    std::chrono::nanoseconds res = std::chrono::steady_clock::now() - m_alivetime;
    std::chrono::milliseconds millisec = std::duration_cast<std::chrono::milliseconds>(res);
    return millisec.count();
}

} /*end ns mysql*/