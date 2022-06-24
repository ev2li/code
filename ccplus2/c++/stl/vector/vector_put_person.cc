#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
        brief:vector容器中存放自定义的数据类型
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

void test01(){
        vector<Person> v;

        Person p1("aaaa", 30);
        Person p2("bbbb", 40);
        Person p3("cccc", 50);
        Person p4("dddd", 60);
        Person p5("eeee", 70);

        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);
        v.push_back(p5);

        for(auto it = v.begin(); it != v.end(); it++){
                cout << "姓名" << it->m_name << ", 年龄:" << it->m_age << endl;
        }
}

void test02(){
        vector<Person*> v;

        Person p1("aaaa", 30);
        Person p2("bbbb", 40);
        Person p3("cccc", 50);
        Person p4("dddd", 60);
        Person p5("eeee", 70);

        v.push_back(&p1);
        v.push_back(&p2);
        v.push_back(&p3);
        v.push_back(&p4);
        v.push_back(&p5);


        for(auto it = v.begin(); it != v.end(); it++){
                cout << "姓名" << (*it)->m_name << ", 年龄:" <<  (*it)->m_age << endl;
        }
}

int main(){
        test01();
        test02();        
        return 0;
}