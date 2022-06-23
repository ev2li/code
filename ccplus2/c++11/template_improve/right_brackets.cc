#include <iostream>

using namespace std;

template<int i> class X{};
template<class T> class Y{};

int	main(int argc, char **argv)
{
    Y<X<10> > obj1; //c++11之前的写法两个右尖括号之间必须有空格(认为它是右移)
    Y<X<10>> obj2;  //c++11的写法
    return 0;
}

