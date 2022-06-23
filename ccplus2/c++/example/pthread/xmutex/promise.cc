#include<iostream>
#include<thread>
#include<future>
#include<string>
using namespace std;

void TestFuture(promise<string> p){
    cout << "begin TestFuture" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "begin set value" << endl;
    p.set_value("TestFuture value");
    this_thread::sleep_for(chrono::seconds(3));
    cout << "end TestFuture" << endl;
}

int main(){
    //异步传输变量存储
    promise<string> p;
    //用来获取线程异步值获取
    auto future = p.get_future();

    auto th = thread(TestFuture, move(p));
    cout << "begin future.get()" << endl;
    cout << "future get() = " << future.get() << endl;
    cout << "end future.get()" << endl;
    th.join();
    return 0;
}