#include <iostream>

using namespace std;

void func(int a){
    cout << __LINE__ << a << endl;
}

void func(int* p){
    cout << __LINE__ << endl;
}

int	main(int argc, char **argv)
{
    int *p = NULL;
    int *p2 =  0;

    func(0);
    // func(NULL);

    //nullptr 只能给指针赋值

    p = NULL;
    p2 = nullptr;

    if(p == p2){
        cout << "equal\n";
    }

    //不能给一下普通整型变量赋值给nullptr,无法从nullpt转换成int
    // int tmp = nullptr;//err

    return 0;
}
