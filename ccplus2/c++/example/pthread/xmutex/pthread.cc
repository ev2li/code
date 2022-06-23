#include<iostream>
#include<thread>
using namespace std;

void ThreadMain(){
    std::cout << "begin sub thread main:" << this_thread::get_id() << std::endl;
    for(int i = 0; i < 10; i++){
        cout << "in thread " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    std::cout << "end  sub thread main:" << this_thread::get_id() << std::endl;
}


int main(){
    cout << "main thread ID:" << this_thread::get_id() << endl;
    thread th(ThreadMain);
    cout << "begin wait sub thread" << endl;
    th.join();
    cout << "end wait sub thread" << endl;
    return 0;
}