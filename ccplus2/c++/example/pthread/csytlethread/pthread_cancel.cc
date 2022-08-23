#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

pthread_t pid[3];

void* thread_run_1(void* arg){
    std::cout << "Now in thread 1" << std::endl;

    int sum = 0;
    int state, oldstate;
    state = PHTREAD_CANCEL_DEFERRED;
    pthread_setcancelstate(state, &oldstate);

    std::cout << "oldstate is " << (state == oldstate ? "Deferred":"Async") << std::endl;

    for(int i = 1; i <= INT_MAX; ++i);

    cout<<"before testcancel"<<endl;
    pthread_testcancel();

    cout<<"after testcancel"<<endl;

    cout<<"thread 1 done!"<<endl;
}

void* thread_run_2(void* arg){
    cout<<"Now in the thread 2"<<endl;
    pthread_cancel(pid[1]);
    sleep(2);
    cout<<"thread 2 done!"<<endl;
}

int main(){
    pid[0] = pthread_self();
    if (pthread_create(&pid[1],NULL,thread_run_1,NULL) != 0){
        cout<<"error create thread 1"<<endl;
        return -1;
    }
    if (pthread_create(&pid[2],NULL,thread_run_2,NULL) != 0){
        cout<<"error create thread 2"<<endl;
         return -1;
    }

    sleep(5);

    cout<<"Main thread done!"<<endl;
}       