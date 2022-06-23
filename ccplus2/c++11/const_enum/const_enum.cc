#include <iostream>

using namespace std;


int	main(int argc, char **argv)
{
    enum Status{OK, Error};
    //OK重定义,以前定义是"枚举数"
    //enum Status2{OK, Error};
    Status flag = OK;
    cout << sizeof(OK) << endl; //4
    return 0;
}
