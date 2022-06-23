#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A(int i):a(i){

    }
public:
    int a;
};

class B
{
public:
    int data{1};
    int data2 =  1;
    A tmp{10};
    string name{"mike"};
};

int main(int argc, char const *argv[])
{
    B obj;
    cout << obj.data << endl;
    cout << obj.data2<< endl;
    cout << obj.tmp.a << endl;
    cout << obj.name << endl;

    return 0;
}
