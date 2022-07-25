#include <iostream>
using namespace std;

/*
    @brief 申请内存
*/

class A{
public:
    A():age(0),sex(true),bChild(true){

    }
    void setAge(int age){
        this->age = age;
    }
    int getAge(){
        return this->age;
    }
    static void* operator new(size_t size){
        return malloc(size);
    }
    static void operator delete(void* p, size_t size){
        free(p);
    }
    static void operator delete(void* p){
        free(p);
    }    
private:
    int age;
    bool sex;
    bool bChild;
};

class B : public A{

};

void test01(){
    A *a1 = new A();//分配了一块内存，调用默认构造函数
    /* 这段是分配的过程，并不是能运行的代码
    void *p = (void*)malloc(sizeof(A));
    A *a6 = static_cast<A*>(p);
    a1->A::A();
     */
    a1->setAge(100);
    std::cout << "age:" << a1->getAge()<< std::endl;
    // A *a3 = new(a1)A; //placement new 调用默认构造函数
    // delete a3;
    char* tmpMem = (char*)::operator new(sizeof(A));
    A *a4 = ::new(tmpMem)A;
    ::operator delete(tmpMem);
    // delete a4; //fault: double free

    void* tempMem = (void*)malloc(sizeof(A));
    A *a5 = ::new(tmpMem)A;
    free(tempMem);
    A* a2 = new A[10];
    delete []a2;
    std::cout << sizeof(A)<< std::endl;
    std::cout << "age:" << a1->getAge()<< std::endl;
    delete a1;
}

int main(){
    test01();
    return 0;
}