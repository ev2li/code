#include <iostream>
#include <string>

using namespace std;

//通过全局函数打印Person信息

template<class T1, class T2>
class Person{
        //全局函数的类内实现
        friend void printPerson(Person<T1, T2> p){
                cout << "姓名:" << p.m_name << ", 年龄:   " << p.m_age << endl;
        }

public:
        Person(T1 name, T2 age){
                 this->m_name = name;
                 this->m_age = age;        
        }

private:
        T1 m_name;
        T2 m_age;
};


void test01(){
        Person<string, int>p("Tom", 20);
        printPerson(p);
}

int main(){
        test01();
        return 0;
}