#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::mutex mtx; //全局互斥锁
std::condition_variable cv; //全局条件变量
bool ready = false; //全局标识位

void do_print_id(int id){
	std::unique_lock<std::mutex> lck(mtx); //加锁互斥量

	while(!ready){
		cv.wait(lck); 
		/*当ready == false时,while语句执行到wait这里,然后就阻塞在这行,等待通知信号,同时解锁互斥量
		  不影响其它线程获取锁
		  当cv.notify_all();唤醒所有线程,执行到这句wait就收到了信号就被唤醒开始干活,首先就是不断的尝试
		  重新获取并加锁互斥量,若获取不到锁就卡在这里反复尝试加锁,获取到锁以后才往下执行
		*/
	}
	std::cout << "thread" << id << endl;
}

void go(){
	std::unique_lock<std::mutex> lck(mtx);
	ready = true;
	cv.notify_all(); //唤醒所有线程
}

int main(){
	std::thread threads[10];
	for(int i = 0; i < 10; i++){
		threads[i] = std::thread(do_print_id, i);
	}

	std::cout << "10 threads ready to race..." << std::endl;
	go();	
	for(auto &th : threads){
		th.join();
	}
	return 0;
}