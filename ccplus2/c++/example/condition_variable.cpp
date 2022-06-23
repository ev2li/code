#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

condition_variable cond_var;

mutex u_mutex;
bool ready = false;

void first_thread_job(){
	unique_lock<mutex> lock(u_mutex);

	//使用wait()进行等待
	cout << "thread wait" << endl;
	cond_var.wait(lock);
	cout << "This is the first thread " << endl;
}

void second_thread_job(){
	unique_lock<mutex> lock(u_mutex);
	//使用wait进行等待,传入第二个参数
	cout << "thread wait" << endl;
	cond_var.wait(lock, [](){return ready;});
	cout << "This is the second thread " << endl;
}

int main(){
	thread first_thread(first_thread_job);
	thread second_thread(second_thread_job);

	cout << "wait 5 millsecond..." << endl;
	this_thread::sleep_for(std::chrono::millsecond(5));
	//使用notify_one()唤醒线程
	cout << "thread notify_one" << endl;
	cond_var.notify_one();
	//回传ready判断是否要停止等待
	ready = true;
	//使用notify_one()唤醒线程
	cout << "thread notify_one" << endl;
	cond_var.notify_one();
	first_thread.join();
	second_thread.join();

	return 0;
}