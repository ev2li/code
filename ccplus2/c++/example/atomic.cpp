#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

//定义原子变量
atomic_int atomic_a(0);

void first_thread_job(){
	for(int i = 0; i < 3; i++){
		atomic_a += 1;
		cout << "This is thr first thread " << atomic_a << endl;
	}
}

int main(){
	thread first_thread(first_thread_job);
	first_thread.join();

	return 0;
}