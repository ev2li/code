#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <memory>
#include <functional>
#include <future>

using namespace std;

typedef std::chrono::steady_clock SETADY_CLOCK;
typedef std::chrono::steady_clock::time_point TIME_POINT;

void pring_diff_time(const TIME_POINT& t1, const TIME_POINT& t2){
	std::chrono::duration<double, std::milli> dTimeSpan = std::chrono::duration<double, std::milli>(t2 - t1);
	std::cout << "time span: " << dTimeSpan.count() << "ms\n";
}


int calculateA(){
	this_thread::sleep_for(std::chrono::milliseconds(1));
	return 1;
}

//计算B函数
int calculateB()
{
    //延迟2ms
    this_thread::sleep_for(std::chrono::milliseconds(2));
	return 2;
}
 
//计算C函数
int calculateC()
{
    //延迟3ms
    this_thread::sleep_for(std::chrono::milliseconds(3));
	return 3;
}

void test_async_time(){
	int sum = 0;
	TIME_POINT t11 = SETADY_CLOCK::now();	
	std::future<int> f1 = std::async(calculateA);
	std::future<int> f2 = std::async(calculateB);
	std::future<int> f3 = std::async(calculateC);
	sum = f1.get() + f2.get() + f3.get();
	TIME_POINT t22 = SETADY_CLOCK::now();
	std::cout << "test_thread_time result is : " << sum << " ";
	pring_diff_time(t11, t22);
}

int main(){
	test_async_time();
	return 0;
}

