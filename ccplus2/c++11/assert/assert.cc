#include <iostream>

using namespace std;


int	main(int argc, char **argv)
{
    bool flag = false;
    //运行时检查条件,如果条件为真,往下执行,如果条件为假,中断提示错误
    // assert(flag == true); //条件为假,中断
    assert(flag  == false); //条件为真,往下执行

    cout << "Hello c++\n";
    return 0;
}