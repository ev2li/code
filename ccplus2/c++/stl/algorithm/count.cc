#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    @brief
*/

void printVector(const std::vector<int>& v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
}

class Person{
public:
        Person(std::string name, int score){
                this->m_name = name;
                this->m_score = score;
        }
        bool operator==(const Person& p){
                if(this->m_score == p.m_score){
                        return true;
                }
                return false;
        }
public:
        std::string m_name;
        int m_score;
};


void test01(){
        std::vector<int> v;
        v.push_back(0);
        v.push_back(2);
        v.push_back(3);
        v.push_back(0);
        v.push_back(4);
        v.push_back(5);
        v.push_back(5);

        printVector(v);

        auto it = std::count(v.begin(), v.end(), 3);
        if(it){
                std::cout << it << std::endl;
        }else{
                std::cout << "没有" << std::endl;
        }
}

void test02(){
        std::vector<Person> v;
        Person p1("aa" , 30);
        Person p2("bb" , 35);
        Person p3("cc" , 35);
        Person p4("dd" , 30);

        Person p5("de", 35);
        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);

        auto rt = std::count(v.begin(), v.end(), p5);
        if(rt){
                std::cout << rt << std::endl;
        }else{
                std::cout << "没有" << std::endl;
        }
}

int main(){
        // test01();
        test02();
        return 0;
}