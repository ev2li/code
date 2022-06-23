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

int calulateA(){
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

void test_common_time(){
	TIME_POINT t1 = SETADY_CLOCK::now();
	int c = calulateA() + (calculateB() + calculateC());
	TIME_POINT t2 = SETADY_CLOCK::now();
	std::cout << "test_common_time result is : " << c << " ";
	pring_diff_time(t1, t2);
}

int main(){
	test_common_time();
	return 0;
}

