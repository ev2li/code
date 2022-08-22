#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <queue>
#include "MysqlConn.h"
#include <string>
#include <mutex>
#include <condition_variable>

namespace Mysql {
class ConnectionPool{
public:
    static ConnectionPool* getConnectPool();
    ConnectionPool(const ConnectionPool& obj) = delete; //拷贝构造函数
    ConnectionPool& operator=(const ConnectionPool& obj) = delete; //赋值操作符重载
    std::shared_ptr<MysqlConn> getConnection();
    ~ConnectionPool();

private:
    ConnectionPool();
    bool parseJsonFile();
    void produceConnection();
    void recycleConnection();
    void addConnection();

    std::string m_ip;
    std::string m_user;
    std::string m_password;
    std::string m_dbName;
    unsigned short m_port;
    int m_minSize;
    int m_maxSize;
    int m_timeout;
    int m_maxIdleTime;
    std::queue<MysqlConn*> m_connectionQ;
    mutex m_mutexQ;
    std::condition_variable m_conditionQ;
};

}

#endif