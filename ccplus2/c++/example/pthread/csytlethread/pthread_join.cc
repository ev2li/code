#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>


#define N 64

int a = 10;

void *handler(void *arg){
    printf("a=%d,%s\n", a, (char*)arg);
    strcat((char*)arg, "......");
    pthread_exit(arg);
}

int main(){
    pthread_t tid;
    char buf[N] = {"welcome"};
    void *result;

    if(pthread_create(&tid, NULL, handler, (void*)buf) != 0){
        exit(-1);
    }
    printf("\n");

    pthread_join(tid, &result);
    printf("ret:%s\n", (char*)result);

    return 0;
}