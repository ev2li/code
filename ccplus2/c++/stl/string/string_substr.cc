#include <iostream>
#include <string>
using namespace std;

void test01(){
        string str = "hello";
        string substr = str.substr(1, 3);
        cout << substr << endl;
}

void test02(){
        string email = "zhangli@sina.com";
        int pos = email.find('@');
        string name = email.substr(0, pos);
        cout << name << endl;
}

int main(){
        test01();
        test02();
        return 0;
}