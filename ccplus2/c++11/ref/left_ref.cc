#include <iostream>

using namespace std;
/*
    左值:可以取地址,有名字
    右值:不能取地址,没有名字(字面常量,表达式,函数的非引用返回值等)
    引用:给一个内存起一个别名,定义时必须要初始化
*/

int& func(){
    static int tmp;
    return tmp;
}

void test01(){
    int a;
    int& b = a;
    // int&c = 1; //error
    const int &d = a; //ok
    const int &e = 1; //ok

    const int &f = func();//ok

    const int tmp  = 10; 
    const  int &g = tmp;//ok
}

int func01(){
    return 10;
}

void test02(){
    //右值引用
    int&& a = 10;

    int&& b = func01(); //ok
    int i = 10;
    int j = 20;
    int && c = i + j;

    int k = 10;
    // int&& d = k;// err不能把一个左值赋值给一个右值引用
}

void test(int& tmp){
    cout << "左值 = " << tmp << endl;
}

void test(int&& tmp){
    cout << "右值 = " << tmp << endl;
}

int	main(int argc, char **argv)
{
    //左值可以取地址
    //右值不能&
    int a = 10;
    test01();
    test02();
    test(a); //左值引用调用
    test(111); //右值引用调用 
    return 0;
}

