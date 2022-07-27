#include <iostream>
#include <new>
using namespace std;

namespace ev2li {
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

void test_array_new_and_placement_new(){
    std::cout << "test_placement_new()..." << std::endl;
    size_t size = 3;
    //case 1, 模拟memory pool作法,array new + palcement new崩溃
    {
        A* buf = (A*)(new char[sizeof(A) * size]);
        A* tmp = buf;

        std::cout << "buf="  << buf  << " tmp="  << tmp << std::endl;

        for (size_t i = 0; i < SIZE_MAX; i++){
            new (tmp++)A(i);
        }
        std::cout << "buf="  << buf  << " tmp="  << tmp  << std::endl;
        // delete[] buf;  crash
        delete buf; //dtor just one time ~[0]
        std::cout << "end..." << std::endl;
    }

    //case 2
    //回頭測試單純的 array new
    {
        A* buf = new A[size];  //default ctor 3 次. [0]先於[1]先於[2])
        //A必須有 default ctor, 否則 [Error] no matching function for call to 'jj02::A::A()'
        A* tmp = buf;

        cout << "buf=" << buf << "  tmp=" << tmp << endl;

        for (size_t i = 0; i < size; ++i)
            new (tmp++) A(i);       //3次 ctor placement new

        cout << "buf=" << buf << "  tmp=" << tmp << endl;

        delete[] buf;    //dtor three times (次序逆反, [2]先於[1]先於[0])   
    }
    
}

}//end ns ev2li

int main(){
    ev2li::test_array_new_and_placement_new();  
    return 0;
}