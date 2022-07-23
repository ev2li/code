#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
   int i = 0;
   while (true) {
        i++;
        std::cout << "main-running-" << i << std::endl;
        sleep(1);
   }
   return 0;
}