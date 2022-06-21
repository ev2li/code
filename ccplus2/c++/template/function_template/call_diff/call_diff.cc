#include <iostream>
using namespace std;

/*
     普通函数和函数模板的调用规则 
     1.如果函数模板和普通函数都可以实现，那么优先调用普通函数
     2.可以通过空模板参数列表来强制调用函数模板
     3.函数模板也可以发生重载
     4. 如果函数模板可以产生更好的匹配，优先调用函数模板

     总结：如果写了模板函数，最好不要定义普通函数
*/

void myPrint(int a, int b){
        cout << "调用的是普通函数" << endl;
}
#if 0
{
        cout << "调用的是普通函数" << endl;
}
#endif

template<class T>
void myPrint(T a, T b){
        cout << "调用的模板函数" << endl;
}
template<class T>
void myPrint(T a, T b, T c){
        cout << "调用重载的模板函数" << endl;
}

void test01(){
        int a = 10;
        int b = 20;
        // myPrint(a, b); // 优先调用普通函数        

        //通过空模板参数列表，强制调用函数模板
        myPrint<>(a, b);
        myPrint<>(a, b, 100);

        //如果函数模板产生更好的匹配，优先调用函数模板
        char c1 = 'a';
        char c2 = 'b';

        myPrint(c1, c2); //调用函数模板
}

int main(){
        
        return 0;
}