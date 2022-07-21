
#include <iostream>
#include "SoTest.h"

class MainTest: public SoTest{
public:
        void func2(){
                std::cout << "main func2"<< std::endl;
        }
        
        void func3(){
                std::cout << "main func3"<< std::endl;
        }
        
};

int main(int argc, char const *argv[]){
        MainTest t1;
        t1.func1();
        t1.func2();
        t1.func3();
        return 0;
}