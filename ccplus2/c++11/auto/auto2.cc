#include <iostream>
#include <vector>
using namespace std;

//auto易错点如下

/*void func(auto a){

} //不支持函数参数类型是auto
*/

/** auto变量不能作为自定义类型的成员变量
struct Test
{
    int a;
    auto b = 10;
};
*/
 
int	main(int argc, char **argv)
{
    //auto定义变量时,必须初始化
    // auto b[3] = {1,2,3}; 不能是auto数组

    //模块实例化类型不能是auto类型
    vector<int> a;
    // vector<auto> b = {1};
    return 0;
}
