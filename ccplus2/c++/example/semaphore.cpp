#include <thread>
#include <iostream>
#include <semaphore.h>
/**
 * #初始化semaphore
 * sem_init(sem_t *sem, int pshared, unsigned int value);
 * #定义Semaphore的名称
 * sem_t sem;
 * #设定为0表示仅供当前的process及其Thread使用,非0表示此Semaphore与其他process共用
 * int pshared
 * #设定Semaphore计数器
 * unsigned int value
 * #用来阻塞该线程,直到Semaphore的值大于0,若解除阻塞后,Semaphore的值会减1,表示可执行的次数减1
 * sem_wait(sem_t *sem);
 * #当有线程阻塞在信号上,调用此函数会全其中一个线程解除阻塞,此时semaphore的值加1 
 * sem_post(sem_ *sem);
 * #删除Semaphore
 * sem_destory(sem_t *sem);
 */
using namespace std;

sem_t binSem;
int a;

void first_thread_job(){
	sem_wait(&binSem);
	for(int i = 0; i < 3; i++){
		a += 1;
		cout << "This is the first thread" << a << endl;
	}
}

void second_thread_job(){
	for(int i = 0; i < 3; i++){
		a -= 1;
		cout << "This is the second thread" << a << endl;
	}
	sem_post(&binSem);
}

int main(){
	int res;
	res = sem_init(&binSem, 0, 0);
	thread first_thread(first_thread_job);
	thread second_thread(second_thread_job);

	first_thread.join();
	second_thread.join();
	return 0;
}