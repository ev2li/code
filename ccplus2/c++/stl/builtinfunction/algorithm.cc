#include <iostream>
#include <functional>
using namespace std;

/*
    @brief 算术仿函数 
    negate取反仿函数 plus(+) minus(-) multiplies(x) divides(x) modulus(取模)
*/

void test01(){
       std::negate<int> n;
       std::cout << n(50) << std::endl;
}

void test02(){
        std::plus<int> n;
        std::cout << n(50, 80) << std::endl;
}

int main(){
        // test01();
        test02();
        return 0;
}