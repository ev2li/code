#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* StartFuntion(void* arg){
    int a = 10;
    pthread_exit((void*)a);
}

int main(){

    pthread_t my_pthread_t;
    if(0 != pthread_create(&my_pthread_t, NULL, StartFuntion, NULL)){
        printf("pthread_create error! \n");
        return -1;
    }

    void *p = NULL;
    if(0 != pthread_join(my_pthread_t, &p)){
        printf("pthread_join error!\n");
        return -1;
    }
    printf("ret = %d\n", p);
    return 0;
}