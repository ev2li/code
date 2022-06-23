#include <iostream>

using namespace std;


int	main(int argc, char **argv)
{
    int a = 10;
    // int && b = a; //err 左值不能绑定到右值引用
    int&& b = std::move(a); //将左值转换成右值
    cout << "b = " << b << endl;
    return 0;
}

