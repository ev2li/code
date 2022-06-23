#include <iostream>

using namespace std;

class Test{
public:
    //委托构造一定要通过初始化列表的方式
    Test(): Test(1, 'a'){

    }

    Test(int x):Test(x, 'a'){

    }

    Test(char x):Test(10, x){

    }

public:
    int a;
    char b;

private:
   Test(int x, char y):a(x),b(y){

    }    
};

int	main(int argc, char **argv)
{
    Test obj; //Test():Test(1, 'a');
    cout << obj.a << endl;
    cout << obj.b << endl;
    Test obj2(10);
    cout << obj2.a << endl;
    cout << obj2.b << endl;

    Test obj3('c');
    cout << obj3.a << endl;
    cout << obj3.b << endl;
    return 0;
}

