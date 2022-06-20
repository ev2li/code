#include <iostream>
using namespace std;

//函数模板
template<class T>
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp; 
}

int main(){ 
    int a = 3;
    int b = 4;
    //自动类型推导
   mySwap(a, b);
    cout << a << endl;
    cout  << b << endl;
    return 0;
}
