#include <iostream>
#include <complex>
#include <memory>
using namespace std;
namespace jj01{
    void test_primitives(){
        std::cout << "test_primitives" << std::endl;
        void* p1 = malloc(512);//512bytes
        free(p1);

        std::complex<int>* p2 = new std::complex<int>; //one object
        delete p2;

        void* p3 = ::operator new(512); //512bytes
        ::operator delete(p3);
        //以下使用c++标准库提供的allocators,其接口虽有标准规格，但实现厂商尚未完全遵守；下面三者形式略异。
#ifdef _MSC_VER
        //以下两都是 non-static，定要通過 object 調用。以下分配 3 個 ints.
        int* p4 = std::allocator<int>().allocate(3, (int*)0);
        p4[0] = 666;
        p4[1] = 999;
        p4[2] = 888;
        std::cout << "p4[0] = " << p4[0]<< std::endl;
        std::cout << "p4[1] = " << p4[1]<< std::endl;
        std::cout << "p4[2] = " << p4[2]<< std::endl;
        std::allocator<int>().deallocate(p4, 3);
#endif

#ifdef __BORLANDC__
        //以下两函数都是 non-static，定要通过 object 调用。以下分配 5 个 ints.
        int* p4 = std::allocator<int>().allocate(5);
        std::allocator<int>().deallocate(p4, 5);
#endif

#ifdef __GNUC__
        //以下两函数都是 static，可通过全名调用之。以下分配 512 bytes.
        //void* p4 = alloc::allocate(512); 
        //alloc::deallocate(p4,512);   

        //以下两函数都是 non-static，定要通过 object 调用。以下分配 7 个 ints.    
        void* p4 = std::allocator<int>().allocate(7);
        std::allocator<int>().deallocate((int*)p4, 7);

        //以下两函数都是 non-static，定要通过 object 调用。以下分配 9 个 ints.  
        void* p5 = __gnu_cxx::__pool_alloc<int>().allocate(9);
        __gnu_cxx::__pool_alloc<int>().deallocate((int*)p5, 9);
#endif
    }
} // namespace name


int main(){
    return 0;
}