#include<iostream>
#include<pthread.h>
#include<unistd.h>

void* thr_fn(void* arg){
    int i = *(int*)arg;
    std::cout << i << std::endl;
    return ((void*)0);
}

int main(){
    pthread_t tid;
    int j = 2;
    pthread_create(&tid, NULL, thr_fn, &j);
    sleep(1);
    return 0;
}