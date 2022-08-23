#include <iostream>
#include <thread>

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

int num = 0;
pthread_spinlock_t spin_lock;

int64_t get_current_timestamp(){
    struct timeval now = {0,0}; //定义时间结构体,参数是秒,后面是微秒
    gettimeofday(&now, NULL); //获取当前时间 
    return now.tv_sec * 1000000 + now.tv_usec;
}

void thread_proc(){
    for(i = 0;i < 100000000;i++){
        pthread_spin_lock(&spin_lock);
        ++num;
        pthread_spin_unlock(&spin_lock);
    }
}

int main(){
    pthread_spin_init(&spin_lock, PTHREAD_PROCESS_PRIVATE);
    int64_t start = get_current_timestamp();
    std::thread t1(thread_proc), t2(thread_proc);
    t1.join(); t2.join();
    std::cout << "num: " << num << std::endl;
    int64_t end = get_current_timestamp();
    std::cout << "cost" << end-start << " us" << std::endl;
    pthread_spin_destory(&spin_lock);
    return 0;

}
