#include <iostream>
#include <vector>
using namespace std;

double foo(){
    return 1.1;
}

struct Test{
    int a;
};

void func(std::vector<int> &tmp){
    for(auto i = tmp.begin(); i != tmp.end(); i++){
        //
    }
}

int	main(int argc, char **argv)
{
    int a = 1;
    auto b = 1;
    auto c = foo();
    Test str = {0};
    auto d = str; //d的类型就是str
    return 0;
}
