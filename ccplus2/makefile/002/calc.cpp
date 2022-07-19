#include <iostream>
#include "add.h"
#include "sub.h"
#include "mutli.h"

int main(){
        int a = 1;
        int b = 2;
        std::cout << add(a,b) << std::endl;
        std::cout << sub(a,b) << std::endl;
        std::cout <<mutli(a, b) << std::endl;
        return 0;
}
