#include <iostream>
using namespace std;

/*
    @brief 求空类的大小
*/

class A{
public:
    virtual void Test();
    virtual void TestA();
private:
    int age;
    bool sex;
    bool bChild;
};

class B : public A{

};

void test01(){
    std::cout << sizeof(A)<< std::endl;
    std::cout << "sizeof(B):" << sizeof(B)<< std::endl;
}

int main(){
    test01();
    return 0;
}