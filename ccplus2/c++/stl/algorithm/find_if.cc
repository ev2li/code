#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
    @brief
*/

class MyFun{
public:
        bool operator()(int v){
                return v > 5;
        }
};

void printVector(const std::vector<int>& v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
}

void test01(){
        std::vector<int> v;
        for (size_t i = 0; i < 10; i++) {
                v.push_back(i);
        }
        printVector(v);
        auto it = std::find_if(v.begin(), v.end(), MyFun());

        if(it != v.end()){
                std::cout << "有" << std::endl;
        }else{
                std::cout << "没有" << std::endl;
        }
}


class Person{
public:
        Person(std::string name,  int age):m_name(name), m_age(age){

        }

       /* bool operator==(const Person& oth){
                if(this->m_name == oth.m_name && this->m_age == oth.m_age){
                        return true;
                }else{
                        return false;
                }
        }*/
public:
        std::string m_name;
        int m_age;
};

class Greater20{
public:
        bool operator()(Person& p){
                return p.m_age > 20;
        }
};

void test02(){

        std::vector<Person> v;
        Person p1("aaa", 10);
        Person p2("bbb", 30);
        Person p3("ccc", 50);
        Person p4("dddd", 20);

        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);

        auto it = find_if(v.begin(), v.end(),  Greater20());

        if(it != v.end()){
                std::cout << "有" << it->m_name << " " << it->m_age <<  std::endl;
        
        }else{
                std::cout << "没有" << std::endl;
        }
}


int main(){
        // test01();
        test02();
        return 0;
}