#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

void  SystemInit(){
    cout << "Call SystemInit" << endl;
}

void SystemInitOne(){
    static std::once_flag flag;
    std::call_once(flag, SystemInit);
}

int main(){
    SystemInitOne();
    SystemInitOne();

    for(int i = 0; i < 3; i++){
        thread th(SystemInitOne);
        th.detach();
    }
    getchar();
    return 0;
}

/**
 * @brief 线程状态
 * 初始化(Init):该线程正在被创建
 * 就绪(Ready):该线程在就绪列表中,等待CPU调度
 * 运行(Running):该线程正在运行
 * 阻塞(Blocked):该线程被阻塞挂起,Blocked状态包括:pend(锁,事件,信号量等阻塞),
 * suspend(主动pend),delay(延时阻塞),pendtime(因为锁,事件,信号量时间等超时等待)
 * 退出(Exit):该线程运行结束,等待父线程回收其控制块资源
 */