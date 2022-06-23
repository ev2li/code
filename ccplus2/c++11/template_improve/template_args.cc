#include <iostream>

using namespace std;

//1.普通函数的默认参数
void func(int a = 3){

}

//2.类模板也是可以支持默认的模板参数,必须是从右往左的
template<class T, class T2 = int>
class A{

};

//3.c++11才支持函数模板带默认的模板参数,不必须是从右往左
template<class T = int, class T2> void func2(T a, T2 b){}

int	main(int argc, char **argv)
{
    
    return 0;
}

