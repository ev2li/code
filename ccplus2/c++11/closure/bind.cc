#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

void func(int x, int y){
    cout << x << " " << y <<  endl;
}

int	main(int argc, char **argv)
{
    bind(func, 1, 2)();
    //std::placeholders::_1 函数调用时,被第一个参数替换
    //std::placeholders::_2 函数调用时,被第二个参数替换

    bind(func, std::placeholders::_1, std::placeholders::_2)(11, 22);
    bind(func, 11, _1)(33);
    
    return 0;
}

