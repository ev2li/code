#include <iostream>
#include <string>

using namespace std;

/*
        @brief类模板作为函数参数
        1.指定传入的类型 ---直接显示对象的数据类型
        2.参数模板化 --- 将对象中的参数变为模板进行传递
        3.整个类模板化 --- 将这个对象的类型，模板化进行传递

        总结：
                最常用的是指定传入类型
*/

template<class T1, class  T2>
class Person{
public:
        Person(T1 name, T2 age){
                this->m_name = name;
                this->m_age = age;
        }

        void showPerson(){
                cout << "姓名: " << this->m_name << " " << "年龄: " << this->m_age << endl;
        }
public:
        T1 m_name;
        T2 m_age;
};

// 1.指定传入的类型
void printPerson01(Person<string, int>& p){
        p.showPerson();
}

//  2.参数模板化
template<class T1, class T2>
void printPerson02(Person<T1, T2>& p){
        p.showPerson();
        cout << "T1的类型:" << typeid(T1).name() << endl;
        cout << "T2的类型:" << typeid(T2).name() << endl;
}

// 整个类模板化
template<class T>
void printPerson03(T& p){
        p.showPerson();
        cout << "T的类型:" << typeid(T).name() << endl;
}

// 1.指定传入的类型 ---直接显示对象的数据类型
void  test01(){
        Person<string, int> p1("张三", 20);
        printPerson01(p1);
}

//  2.参数模板化 --- 将对象中的参数变为模板进行传递
void test02(){
        Person<string, int> p2("李四", 20);
        printPerson02(p2);
}

// 3.整个类模板化 --- 将这个对象的类型，模板化进行传递
void test03(){
        Person<string, int> p3("王五", 20);
        printPerson03(p3);
}

int main(){
        
        return 0;
}