#include <iostream>
#include <memory>
using namespace std;

class Test{
public:
    ~Test(){
        cout << "析构\n";
    }
};

void func01(){
    std::unique_ptr<int> up1(new int(11)); //创建智能指针对象,up1是唯一使用者

    //up1.reset(); //如果是无参,作用是显示释放堆区内存
    up1.reset(new int(22)); //有参,先释放原来堆区内存,重新给up1绑定一个新的堆区内存
    cout <<  *up1 <<  endl;
}

void func02(){
    std::unique_ptr<int> up1(new int(11)); 
    //释放控制权,但不释放堆区内存
    int *p  = up1.release();
    cout << *p << endl;
    // cout << "*p = " << *p << endl; // error
    delete p;
}

int	main(int argc, char **argv)
{
    std::unique_ptr<int> up1(new int(11)); //创建智能指针对象,up1是唯一使用者
    std::cout << "*up1 = " << *up1 << endl; //重载了operator*() 

    {
        std::unique_ptr<Test> up2(new Test); //无需释放
        up2 = nullptr; //人为指定释放堆区空间
        cout << "11111111111111\n";
    }
    cout << "---------------------------\n";
    // std::unique_ptr<int> up3  = up1;  //拷贝构造 err
    std::unique_ptr<int> up3 = std::move(up1); //ok,把up1的使用权转移给up3,up1不能再操作堆区空间
    cout << "*up3 =  " << *up3 << endl;
    // cout << "*up1 =  " << *up1 << endl; //err
    
    return 0; 
}

