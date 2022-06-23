#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    int i;
    decltype(i) j = 0;
    cout << typeid(j).name() << endl;

    float a;
    double b;

    decltype(a + b) c;
    cout << typeid(c).name() << endl;

    vector<int> tmp;
    decltype(tmp.begin()) k;
    for(k = tmp.begin(); k != tmp.end(); k++){

    }

    enum{
        OK,Error
    }flag; //匿名类型的枚举变量

    decltype(flag) flag2;

    /* code */
    return 0;
}
