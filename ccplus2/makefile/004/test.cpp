#include <iostream>
#include "SoTest.h"

using namespace std;

class Test:public SoTest{
public:
        void func2(){
                std::cout << "test-func2"<< std::endl;
        }
          void func3(){
                std::cout << "test-func3"<< std::endl;
        }       
};

int main(){
        Test t1;
        t1.func1();
        t1.func2();
        t1.func3();
        return 0;
}