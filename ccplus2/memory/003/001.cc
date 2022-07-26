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


void test01(){
    A* array1 = new A[10];
    A* array2 = new A[11];
    A* array3 = new A[11];
    A* array4 = new A[7];

    delete []array1;
    delete []array2;
    delete []array3;
    delete []array4;
    std::cout << sizeof(array1)<< std::endl;
}

int main(){
    test01();
    return 0;
}