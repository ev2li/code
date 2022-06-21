#include <iostream>
using namespace std;

/*
        普通函数与函数模板的区别
        1.普通函数调用可以发生隐式类型转换
        2.函数模板用自动类型推导，不可以发生隐式类型转换
        3.函数模板用显示指定类型，是可以发生隐式类型转换的
*/

int myAdd01(int a, int b){
        return a + b;
}

template<class T>
T myAdd02(T a,  T b){
        return a + b;
}

void test01(){
        int a =10;
        int b = 20;

        char c = 'c';
        cout << myAdd01(a, c) << endl;
        cout << myAdd02(a, b) << endl; // ok
        // cout << myAdd01(a, c) << endl; //err
         cout << myAdd02<int>(a, c) << endl; 
}


int main(){
        test01(); 
        return 0;
}