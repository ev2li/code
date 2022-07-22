#include <iostream>

extern void func1();
extern void func2();
using namespace std;

int main(int argc, const char** argv) {
    func1();
    func2();
    std::cout << "std"<< std::endl;
    return 0;
}