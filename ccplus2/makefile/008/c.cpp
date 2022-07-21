#include <iostream>

extern void func1();
extern void func2();

int main(int argc, const char** argv) {
        func1();
        func2();
        return 0;
}