#include <iostream>

using namespace std;


int	main(int argc, char **argv)
{
    //static_assert(常量表达式的条件,提示字符串);
    static_assert(sizeof(void *) == 8, "32位系统不支持");
    cout << "Hello c++\n";
    return 0;
}