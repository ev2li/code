#include <iostream>

using namespace std;

/*常量表达式,发生在编译阶段
 * 限制:
 * 1.函数只能有一个return语句(有极少的特例)
 * 2.函数必须返回值(不能是void函数)
 * 3.在使用前必须已有定义
 * 4.return返回语句表达式中不能使用非常量表达式的函数,全局数据,且必须是一个常量表达式
 */

#if 0
constexpr int func01(){
    constexpr int a =  1;
    return a; //error,函数只能有一个return语句
}
#endif

#if 0
constexpr int func02(){
    //允许包含typedef,using指令,静态断言
    static_assert(1, "fail");
    return 3;
} //这个是ok的
#endif

#if 0
int a = 3;
constexpr int func03(){
    return a;
} //这个是err的,返回全局变量
#endif

#if 0
int test(){
    return 10;
}

constexpr int func04(){
    return test();
} //这个也是err的,不能够使用非常量表达式的函数
#endif 


int	main(int argc, char **argv)
{
    constexpr int func05();
    // constexpr int tmp = func05(); // err
    return 0;
}


constexpr int func05(){
    return 1;
} 