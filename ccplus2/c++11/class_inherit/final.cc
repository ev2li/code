#include <iostream>

using namespace std;

//final阻止类的进一步派生,虚函数进一步重写
class A1 final{ //这个类不能派生
public:
    int a;
};

#if 0
class A2:public A1{
};
#endif

//基类
class B1 {
public:
    virtual void func() final{ //这是最终版本的虚函数,不能再重写

    }
};

#if 0
//派生类重写基类的虚函数
class B2 :public B1{
public:
    virtual void func(){

    }
};
#endif 

int	main(int argc, char **argv)
{
    
    return 0;
}

