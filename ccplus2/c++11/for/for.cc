#include <iostream>

using namespace std;

#if 0
void func(int a[]){ //形参中的数组不是数组,是指针变量,无法确定元素的个数
    for(int& tmp : a){  //基于范围的for,这个范围是要确实范围的
        cout << tmp << endl;
    }
}
#endif 

int	main(int argc, char **argv)
{
    int a[] = {1,2,3,4,5};
    int n = sizeof(a) / sizeof(int);
#if 0
    for (int i = 0; i < n; i++)
    {
        int tmp = a[i];
        cout << tmp << ",";
    }
    cout << endl;
    
    for (int tmp : a)
    {
        cout << tmp << ",";
    }
    cout << endl;
#endif
    for (int i = 0; i < n; i++)
    {
        int &tmp = a[i];
        cout << tmp << ",";
    }
    cout << endl;

    for (int &tmp : a) //数组范围是确定的才可以这样用
    {
        tmp = 2 * tmp;
        cout << tmp << ",";
    }
    cout << endl;
    return 0;
}
