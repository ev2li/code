#include <iostream>
#include <type_traits>

using namespace std;

typedef int int32;

using myint =  int; //c++11方式


int	main(int argc, char **argv)
{
    //is_same判断2个类型是否一致,如果返回真,否则返回假
    cout << std::is_same<int32, myint>::value << endl;
    return 0;
}

