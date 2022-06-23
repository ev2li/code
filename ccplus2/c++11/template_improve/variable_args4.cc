#include <iostream>

using namespace std;

template<class T>
void print(T tmp){
    cout << tmp << endl;
}

template<class ...T>
void expand(T... args){
    //逗号运算符,初始化列表
    int a[] = {(print(args), 0)...};
}


int	main(int argc, char **argv)
{
    expand(1, 2, 3, 4);
    return 0;
}

