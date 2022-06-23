#include <iostream>

using namespace std;

#if 0
class X{
public:
    X(){} //普通无参
    X(const X &){} //拷贝构造
    X& operator=(const  X &) {return *this;} // 赋值运算符重载函数
};
#endif 

class X{
public:
    X(){} //普通无参
    X(const X &) = delete; //拷贝构造,此函数被禁用
    X& operator=(const  X &) = delete; // 赋值运算符重载函数,此函数也被禁用
    X(int a ) = delete;
    void *operator new(size_t) = delete;
    void *operator new[](size_t) = delete;
};

int	main(int argc, char **argv)
{
    X obj1; //普通无参
    // X obj2 = obj1;//拷贝构造  err
    // obj2 = obj1; //err delete修饰

    // X obj3(10); err

    // X *p = new X; err
    // X *p = new X[10]; err
    return 0;

}

