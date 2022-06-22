#include <iostream>
#include <string>

using namespace std;
/*
        总结：
        1.全局函数类内实现 --- 直接在类内声明友元即可
        2.全局函数类外实现 --- 需要提前让编译器知道全局函数的存在，而且在类内要空模板列表
*/
//提前让编译器知道Person
template<class T1, class T2>
class Person;

//全局函数类外实现
template<class T1, class T2>
 void printPerson2(Person<T1, T2> p){
        cout << "姓名:" << p.m_name << ", 年龄:   " << p.m_age << endl;
}

//通过全局函数打印Person信息
template<class T1, class T2>
class Person{
        //全局函数的类外实现
        //加空模板参数列表
        //如果全局函数类外实现，需要让编译器提前知道这个函数的存在
        friend void printPerson2<>(Person<T1, T2> p);

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
        Person<string, int>p("Jerry", 30);
        printPerson2(p);
}

int main(){
        test01();
        return 0;
}