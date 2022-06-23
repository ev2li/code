#include <iostream>
#include <thread>
#include <queue>

using namespace std;

queue<int> q;
queue<int>::size_type q_size;

void first_thread_job(int x){
	q.push(x);
	cout << "This is the first thread" << x << endl;
}

int main(){
	thread first_thread(first_thread_job, 2);
	first_thread.join();

	int a = q.front();
	cout << "The first element is " << a << endl;
	q_size = q.size();
	cout << "The queue length is " << q_size << endl;

	q.pop();

	q_size = q.size();
	cout << "The queue2 length is "<<q_size<<endl;
	return 0;
}