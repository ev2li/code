#include <iostream>

using namespace std;

int GetNum(){
    return 3;
}

const int GetNum2(){
    return 3;
}

/*常量表达式,发生在编译阶段
 * 限制:
 * 1.函数只能有一个return语句(有极少的特例)
 * 2.函数必须返回值(不能是void函数)
 * 3.在使用前必须已有定义
 * 4.return返回语句表达式中不能使用非常量表达式的函数,全局数据,且必须是一个常量表达式
 */
constexpr int GetNum3(){
    return 3; 
}

int	main(int argc, char **argv)
{
    //枚举成员的初始化必须是常量
    //enum {e1 = GetNum(), e2}; //枚举类型 err
    //enum {e1 = GetNum2(), e2}; //枚举类型 err
    enum {e1 = GetNum3(), e2}; //ok
    constexpr int tmp = GetNum3(); //ok
    enum {a1 = tmp, a2}; //ok 发生在编译阶段
    return 0;
}
