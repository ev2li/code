#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

class Test{
public:
    void func(int x, int y){
        cout << x << " " << y <<  endl;
    }

    int a;
};

int	main(int argc, char **argv)
{
    Test obj;
    //绑定成员函数
    std::function<void(int, int)> f1 = bind(&Test::func, &obj, _1, _2);
    f1(11, 22); //obj.func(11, 22);

    std::function<int& ()> f2 = bind(&Test::a, &obj); 
    f2() = 111;//obj.a = 111
    cout << "obj.a = " << obj.a << endl;
    return 0;
}
