#include <iostream>
#include <string>
using namespace std;

namespace jj02 {
class A{
public:
    int id;
    A():id(0){
        std::cout << "default ctor. this=" << this << " id= "  << id << std::endl;
    }
    A(int i):id(i){
         std::cout << "ctor. this=" << this << " id= "  << id << std::endl;
    }
    ~A(){
        std::cout << "dtor. this=" << this << " id= "  << id << std::endl;
    }
};

void test_call_ctor_directly(){
    std::cout << "test_call_ctor_directly()..."<< std::endl;
    string *pstr = new string;
    std::cout << "*pstr:" << *pstr<< std::endl;

    A* pa = new A(1);
    std::cout << pa->id << std::endl;
    delete pa;

    void* p = ::operator new(sizeof(A));
    std::cout << "p=" << p << std::endl;
    A* pb = static_cast<A*>(p); 
    // pb->A::A(); 调用构造函数
    std::cout << pb->id << std::endl;
    pb->~A();
    ::operator delete(pb);
}
} //end ns jj02

int main(){
   jj02::test_call_ctor_directly();
   return 0;
}