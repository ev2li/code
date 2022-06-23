#include <iostream>
#include <functional> 

using namespace std;

/*
c++中,可调用实体主要包括:函数,函数指针,函数引用,可以隐式转换为函数指定的对象,或者实现了operator()对象
*/

//1.普通函数
void func(){
    cout << __func__ << endl;
}

//2.类中静态函数
class Test{
public:
    static int test_func(int a){
        cout << __func__ << "(" << a  << ") ->: ";
        return a;
    }
};

//3.类中的仿函数
class MyFunctor{
public:
    int operator()(int a){
        cout << __func__ << "(" << a  << ") ->: ";
        return a;
    }
};

int	main(int argc, char **argv)
{
    //1.bind普通函数
    std::function<void()> f1 = func;
    f1(); //等价于func()

    //2.绑定类的静态函数
    std::function<int(int)> f2 = Test::test_func;
    cout << f2(3) << endl; //等价于Test::test_func(3)

    //3.绑定类中的仿函数,绑定对象,仿函数调用obj
    MyFunctor obj;
    std::function<int(int)> f3 = obj;
    cout << f3(22) << endl;
    
    return 0;
}

