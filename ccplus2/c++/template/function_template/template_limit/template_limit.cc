#include <iostream>
#include <string>
using namespace std;
/*
        @brief:模板的局限性 
 */


class Person{
public:
        Person(string name, int age){
                this->m_name = name;
                this->m_age = age;
        }        

 public:
        string m_name;
        int m_age;       
};

/*
        @brief:对比两个数据是否相等
*/
template<class T>
bool myCompare(T& a, T& b){
        if(a == b){
                return true;
        }else{
                return false;
        }
}

//利用具体化的Person的版本来实现代码，具体化优先调用
template<> bool myCompare(Person& p1, Person& p2){
        if(p1.m_name == p2.m_name && p1.m_age == p2.m_age){
                return true;
        }else{
                return false;
        }
}

void test01(){
        int a = 10; 
        int b = 20;
        bool ret = myCompare(a, b);

        if(ret){
                cout << "a equal b" << endl;
        }else{
                cout << "a unequal b" << endl;
        }
}

void test02(){
        Person p1("Tom", 10);
        Person p2("Tom", 10);

        bool ret = myCompare(p1, p2);

         if(ret){
                cout << "p1 equal p2" << endl;
        }else{
                cout << "p1 unequal p2" << endl;
        }       
}

int main(){
        test01();
        test02();
        return 0;
}