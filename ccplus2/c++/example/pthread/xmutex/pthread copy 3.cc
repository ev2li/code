#include<iostream>
#include<thread>
#include<string>

using namespace std;

class MyThread{
public:
    string name = "";
    int age = 100;
public:
    void Main(){ //线程入口函数
        cout << "MyThread Main " << name << ":" << age << endl;
    }
};

int main(){
    MyThread myth;
    myth.name = "Test name 001";
    myth.age = 20;

    thread th(&MyThread::Main, &myth);
    th.join();
    return 0;
}