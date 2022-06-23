#include <iostream>

using namespace std;


int	main(int argc, char **argv)
{
    //强类型枚举,enum后面加上class或struct修饰
    enum class Status{OK, Error};
    enum struct Status2{OK, Error};
    
    // Status flag = OK;//err,必须枚举类型的作用域
    Status flag = Status::OK; //ok

    //强类型枚举,可以指定成员变量的类型
    enum struct Status3:char{OK, Error};
    cout << sizeof(Status3::OK) << endl;

    enum struct Status4:long long{OK, Error};
    cout << sizeof(Status4::OK) << endl;
    return 0;
}
