#include <iostream>
using namespace std;

void func01(){
    throw 1;
}

//这个函数不能抛出任何异常
void func02() throw(){
    
}

void func03() noexcept{

}

int	main(int argc, char **argv)
{
    
    return 0;
}