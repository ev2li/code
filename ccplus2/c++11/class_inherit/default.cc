#include <iostream>

using namespace std;

class X{
public:
    X() = default; //让编译器提供一个默认的无参构造函数,这个函数的效率比用户自己写的高

    X(int i){
        a = i;
    }

    int a;    
};

/**
 * default只能修饰类中默认提供的成员函数,无参构造,拷贝构造,赋值运算符重载,析构函数等
 */

#if 0
class X2{
public:
    int f() = default;
    X2(int a) = default;
};

#endif //error
class X3{
public:
    X3(); //让编译器提供一个默认的无参构造函数,这个函数的效率比用户自己写的高

    X3(int i){
        a = i;
    }

    int a;    
};
X3::X3() = default; //default可以放在类的外部

int	main(int argc, char **argv)
{
    // X obj; err 写了带参的构造函数以后,编译器就不会提供默认的无参构造函数了
    return 0;
}

