#include<iostream>
#include<thread>
using namespace std;
bool is_exit = false;

void ThreadMain(){
    std::cout << "begin sub thread main:" << this_thread::get_id() << std::endl;
    for(int i = 0; i < 10; i++){
        if(!is_exit) break;
        cout << "in thread " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    std::cout << "end  sub thread main:" << this_thread::get_id() << std::endl;
}


int main(){
   /* {
    //thread th(ThreadMain); //出错 thread对象被销毁,线程还在运行,在{}内的情况
    }*/
    
    /*{
        thread th(ThreadMain);
        th.detach(); //子线程与主线程分离,守护线程
        //坑:主线程退出后,子线程并不一定退出,子线程访问全局变量会出错
    }*/

    {
        thread th(ThreadMain);
        this_thread::sleep_for(chrono::seconds(1));
        is_exit = true; //通知子线程退出
        cout << "主线程阻塞,等待子线程退出" << endl;
        th.join(); //主线程阻塞,等待子线程退出
        cout << "子线程退出" << endl;
    }

    getchar();
    return 0;
}