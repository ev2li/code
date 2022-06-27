#include <iostream>
#include <queue>
#include <string>

using namespace std;

/*
    @brief queue不允许有遍历的操作 先进先出
*/

class Person{
public:
        Person(std::string name, int age){
                this->m_name = name;
                this->m_age = age;
        }

public:
        std::string m_name;
        int m_age;
};


void test01(){
        //1.创建队列 
        std::queue<Person> q;

        //2.准备数据
        Person p1("A", 10);
        Person p2("B", 20);
        Person p3("C", 30);
        Person p4("D", 40);

        //3.入队
        q.push(p1);
        q.push(p2);
        q.push(p3);
        q.push(p4);

        while(!q.empty()){
                std::cout << "队头 - 姓名: " << q.front().m_name  << ", 年龄:" <<   q.front().m_age << std::endl;
                std::cout << "队尾 - 姓名: " << q.back().m_name  << ", 年龄:" <<   q.back().m_age << std::endl;
                q.pop();
        }

        std::cout << "队列的大小" << q.size()  << std::endl;

}

int main(){
        test01();
        return 0;
}