#include <iostream>
#include <string>
using namespace std;

/*
    @brief 仿函数 
    1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
    2.函数对象超出普通函数的概念，函数对象可以有自己的状态
    3.函数对象可以作为参数传递
*/


class MyAdd{
public:
        int operator()(int a, int b){
                return a + b;
        }
};


void test01(){ 
        MyAdd myAdd;
        std::cout << myAdd(3, 5) << std::endl;
}

class MyPrint{

public:

        MyPrint(){
                this->count = 0;
        }

        void operator()(std::string test ){
                std::cout << test << std::endl;
                this->count++;
        }
public:
        int count; //内部自己的状态
};

void test02(){
        MyPrint myPrint;
        myPrint("hello world");
        std::cout << "myPrint调用的次数" << myPrint.count << std::endl;
}

void doPrint(MyPrint& mp, std::string test){
        mp(test);
}

void test03(){
        MyPrint mp;
        doPrint(mp, "c++");
}

int main(){
        // test01();
        // test02();
        test03();
        return 0;
}