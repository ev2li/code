#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Person{
public:
        Person(NameType name, AgeType age){
                this->m_name = name;
                this->m_age = age;
        }
public:
        NameType m_name;
        AgeType m_age;
};

void test01(){
        Person<string, int> p1("tom", 20);
        cout<< p1.m_name << endl;
}

int main(){
        
        return 0;
}