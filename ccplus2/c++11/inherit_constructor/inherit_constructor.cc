#include <iostream>

using namespace std;


class A {
public:
    A(int x, int y){
        a = x;
        b = y;
    }

protected:
    int a;
    int b;
};

class B:public A {
public:
#if 0
    //通过参数列表给基类构造函数传参
    B(int x, int y):A(x, y){

    }
#endif 
    //继承构造1.不能是默认,拷贝,移动构造 2.不能初始化派生类成员变量 3.基类构造函数不能是私有
    //4.不能是虚继承
    using A::A; 
    void display(){
        cout << "a=" << a << " " << ",b = " << b << endl;
    }
};

int	main(int argc, char **argv)
{
    B obj(10,20);
    obj.display();
    return 0;
}

