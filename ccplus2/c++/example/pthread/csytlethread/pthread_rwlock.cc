#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  <pthread.h>


pthread_rwlock_t rwlock; //创建读写锁
long int love;

void* pth_wr(void* arg){//写操作
    int i = int(arg); //参数类型化
    while(love < 520){
        pthread_rwlock_wrlock(&rwlock);//请求写锁
        printf("write================love = %ld, threadID = %d\n", love += 40, i + 1);//写操作，love每次加40
        pthread_rwlock_unlock(&rwlock);//写锁释放
        sleep(1);
    }
    return NULL;
}

void* pth_rd(void* arg){
    int i = (int)arg;
    while (love <= 520){
        pthread_rwlock_rdlock(&rwlock);//请求读锁
        printf("love = %ld, threadID = %d-------------------- read\n", love, i + 1);
        pthread_rwlock_unlock(&rwlock);//读锁释放
        sleep(1);
    }
    return NULL;    
}

int main(int argc,char argc[]){
    pthread_t pth[10];
    int i;
    pthread_rwlock_init(&rwlock, NULL);
    for(i = 0;i < 5;i++){
        pthread_create(&pth[i],NULL,pth_wr, (void *)i);
    }   
    for(i = 0;i < 5;i++){
        pthread_create(&pth[i],NULL,pth_rd, (void *)i);
    }

    while (1){
        if(love >= 520){
            for (int j = 0; j != 10; j++){
                pthread_join(pth[j], NULL);
            }
            break;
        }
    }
    pthread_rwlock_destroy(&rwlock);
        
    return 0;
}