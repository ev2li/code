#include <iostream>

using namespace std;
//完美转发

template<class T> 
void func(const T&){
    cout << "const T&" << endl;
}

template<class T> 
void func(T&){
    cout << "T&" << endl;
}

template<class T> 
void forward_val(const T& tmp){ //const版本
    func(tmp); // 定义
}


template<class T> 
void forward_val(T &tmp){ //非const版本
    func(tmp); // 定义
}


int	main(int argc, char **argv)
{
    int a = 0;
    const int &b = 1;

    //需要给forward_val重载两个版本const T& 和 T&
    forward_val(a); //左值 T&
    forward_val(b); //const T&

    forward_val(111); //const T&

    return 0;
}

