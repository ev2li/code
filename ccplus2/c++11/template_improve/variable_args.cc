#include <iostream>

using namespace std;

//可变参数的模板参数
template<class ...T> //T叫模板参数包
void func(T... args){ //args叫函数参数包

}

int	main(int argc, char **argv)
{
    func<int>(10);
    func<int, int>(20, 30);
    func<char, int>('a', 10);
    func<char, char*, int>('a', "abc", 10);
    return 0;
}

