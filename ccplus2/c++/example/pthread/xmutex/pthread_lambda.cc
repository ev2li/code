#include<iostream>
#include<thread>
#include<string>

using namespace std;

class TestLambda{
public:
    void Start(){
        thread th([this](){
            cout << "name = " << name << endl;
        });
        th.join();
    }

public:
    string name = "test lambda";
};

int main(){
    thread th([](int i){ cout << "test lambda " << i << endl;}, 123);
    th.join();

    TestLambda test;
    test.Start();
    return 0;
}