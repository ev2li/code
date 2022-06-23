#include <iostream>

using namespace std;

class A1 {
public:
    virtual void func(int a){

    }
#if 0
    //这是第一个虚函数,没有重写,不能用override来修饰
    virtual void func(int a) override{

    }
#endif
};

class A2:public A1{
public:
    //在重写虚函数的地方加上override,要求重写的虚函数和基类一模一样
    virtual void func(int a) override{

    }
};

int	main(int argc, char **argv)
{
    
    return 0;
}

