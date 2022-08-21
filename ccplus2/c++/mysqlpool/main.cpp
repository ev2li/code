#include <iostream>
#include <memory>
#include <string>
#include "MysqlConn.h"
#include "ConnectionPool.h"
#include <chrono>

void op1(int begin, int end){
    for(i = bengin;i < end;i++){
        MysqlConn conn;    
        conn.connect("root", "123456", "testdb", "127.0.0.1");
        char sql[1024] = {0};
        sprintf(sql, "insert into person value(%d, 24, 'man', 'tom')", i);
        conn.update(sql);
    }
}

void op2(ConnectionPool* pool int begin, int end){
    for(i = bengin;i < end;i++){
        std::shared_ptr<MysqlConn> conn = pool->getConnection();
        char sql[1024] = {0};
        sprintf(sql, "insert into person value(%d, 24, 'man', 'tom')", i);
        conn.update(sql);
    }
}

void test(){
#if 0
    std::chrono::steady_clock::time_point begin =  std::chrono::steady_clock::now();
    op1(0, 5000);
    std::chrono::steady_clock::time_point end =  std::chrono::steady_clock::now();
    auto length = end - start;
    std::cout << "非连接池单线程用时:" << length.count() << " 纳秒," 
        << length.count() / 1000/ 1000 << " 豪秒" << std::endl;
#else 
    ConnectionPool *pool = ConnectionPool::getConnectionPool();
    std::chrono::steady_clock::time_point begin =  std::chrono::steady_clock::now();
    op2(pool, 0, 5000);
    std::chrono::steady_clock::time_point end =  std::chrono::steady_clock::now();
    auto length = end - start;
    std::cout << "连接池单线程用时:" << length.count() << " 纳秒," 
        << length.count() / 1000/ 1000 << " 豪秒" << std::endl;    
#endif
}

int query(){
    MysqlConn conn;    
    conn.connect("root", "123456", "testdb", "127.0.0.1");
    std::string sql = "insert into person value(5, 24, 'man', 'tom')";
    bool flag = conn.update(sql);
    std::cout << "flag value:"  << flag << std::endl;

    sql = "select * from person";
    conn.query(sql);
    while (conn.next()){
        std::cout << conn.value(0) << ", "
            << conn.value(1) << ", "
            << conn.value(2) << ", "
            << conn.value(3) << std::endl;
    }
    return 0;
}

void test01(){
#if 1
    MysqlConn conn;
    conn.connect("root", "123456", "testdb", "127.0.0.1");
    std::chrono::steady_clock::time_point begin =  std::chrono::steady_clock::now();
    thread t1(op1 , 0, 1000);
    thread t2(op1 , 1000, 2000);
    thread t3(op1 , 2000, 3000);
    thread t4(op1 , 3000, 4000);
    thread t5(op1 , 4000, 5000);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    std::chrono::steady_clock::time_point end =  std::chrono::steady_clock::now();
    auto length = end - start;
    std::cout << "非连接池单线程用时:" << length.count() << " 纳秒," 
        << length.count() / 1000/ 1000 << " 豪秒" << std::endl;
#else
    ConnectionPool *pool = ConnectionPool::getConnectionPool();
    std::chrono::steady_clock::time_point begin =  std::chrono::steady_clock::now();
    thread t1(op2, pool, 0, 5000);
    thread t2(op2, pool, 1000, 2000);
    thread t3(op2, pool, 2000, 3000);
    thread t4(op2, pool, 3000, 4000);
    thread t5(op2, pool, 4000, 5000);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    std::chrono::steady_clock::time_point end =  std::chrono::steady_clock::now();
    auto length = end - start;
    std::cout << "连接池单线程用时:" << length.count() << " 纳秒," 
        << length.count() / 1000/ 1000 << " 豪秒" << std::endl;   
#endif    
}

int main(){
    // query();
    test();
    return 0;
}