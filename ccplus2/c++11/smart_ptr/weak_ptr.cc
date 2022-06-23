#include <iostream>
#include <memory>

using namespace std;


int	main(int argc, char **argv)
{
    std::shared_ptr<int> p1(new int(11));
    std::shared_ptr<int> p2 = p1;//有2个指针变量绑定堆区内存
    std::weak_ptr<int> wp = p1;
    cout << "num1 = " << p1.use_count() << endl; //打印计数器
    cout << "num1 = " << wp.use_count() << endl; //打印计数器

    //weak_ptr虽然不和堆区空间绑定,可以通过lock函数获取shard_ptr<int对象>
    //有3个指针变量绑定堆区内存
    std::shared_ptr<int> p3 = wp.lock(); 
    cout << "num2 = " << p1.use_count() << endl; //打印计数器
    cout << "num2 = " << wp.use_count() << endl; //打印计数器

    cout << *p1 << ", " << *p2 << ", " << *p3 << endl;
    // cout << *wp << endl; //error 没有重载* 和 ->

    p1.reset();
    p2.reset();
    p3.reset();
    cout << "num3 = " << p1.use_count() << endl; //打印计数器
    cout << "num3 = " << wp.use_count() << endl; //打印计数器

    //当堆区空间释放后,wp.lock获取的返回值为nullptr;
    std::shared_ptr<int> tmp = wp.lock(); 
    if(tmp == nullptr){
        cout << "堆区空间已经释放\n";
    }

    return 0;
}

