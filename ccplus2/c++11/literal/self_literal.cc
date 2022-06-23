#include <iostream>

using namespace std;

/*自定义字面量,名字要求 operator"" xxx
根据c++11的标准,只有以下的参数列表是合法的
char const *
unsigned long long
long double
char const *, size_t
wchar_t const *, size_t
cha16_t const *, size_t
char32 const *. size_t
*/
double operator"" _mm(long double x){
    return x / 1000;
}

double operator"" _m(long double x){
    return x;
}

double operator"" _km(long double x){
    return x * 1000;
}

int	main(int argc, char **argv)
{
    cout << operator"" _mm(1.0) << endl; //传统的调用方式,不推荐使用
    cout << 1.0_mm << endl;
    cout << 1.0_m << endl;
    cout << 1.0_km << endl;
    return 0;
}

