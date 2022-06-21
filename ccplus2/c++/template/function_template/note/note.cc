#include <iostream>
using namespace std;

/*
        1.自动类型推导必须推导出一致的数据类型T，才可以使用
        2.模板必须要确定出T的数据类型，才可以使用
*/

template<typename T>
void mySwap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
}

template<class T>
void func(){
        cout << "func 调用" << endl;
}

void test01(){
        int a = 10; 
        int b = 10;
        char c = 'c';

        // mySwap(a, b); //ok
        // mySwap(a, c); //err 推导不出一致的T类型
        cout << a << endl;
        cout << b<< endl;
}

void test02(){
        // func(); err
        func<int>();
}

int main(){
        
        return 0;
}