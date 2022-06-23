#include <iostream>
#include <typeinfo>
#include <vector>
#include <typeinfo>

using namespace std;
//追踪返回值类型

int func(int a, int b){
    return a + b;
}

auto func2(int a, int b) ->int {
    return a + b;
}

auto func3(int a,  double b) -> decltype(a + b) {
    return a + b;
}

template<class T1, class T2>
auto mul(const T1& t1, const T2& t2) -> decltype(t1 * t2){
    return t1 * t2;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    double b = 11.1;
    auto c = func3(a, b);
    cout  << "c = "<< c << endl;

    auto i = 10;
    auto j = 11.2;
    auto k = mul(i, j);

    cout << k << endl;
    cout << typeid(k).name() << endl;
    return 0;
}
