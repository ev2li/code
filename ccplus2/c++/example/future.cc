#include "future.hpp"
#include <iostream>
#include <future>
#include <chrono>
#include <utility>
#include <thread>
#include <functional>
#include <memory>
#include <exception> 
#include <numeric>
#include <vector>
#include <cmath>
#include <string>
#include <mutex>
 
namespace future_ {
 
///
// reference: http://www.cplusplus.com/reference/future/async/
int test_async_1()
{
 auto is_prime = [](int x) {
 std::cout << "Calculating. Please, wait...\n";
 for (int i = 2; i < x; ++i) if (x%i == 0) return false;
 return true;
 };
 
 // call is_prime(313222313) asynchronously:
 std::future<bool> fut = std::async(is_prime, 313222313);
 
 std::cout << "Checking whether 313222313 is prime.\n";
 // ...
 
 bool ret = fut.get(); // waits for is_prime to return
 if (ret) std::cout << "It is prime!\n";
 else std::cout << "It is not prime.\n";
 
 return 0;
}
 
///
// reference: http://www.cplusplus.com/reference/future/launch/
int test_async_2()
{
 auto print_ten = [](char c, int ms) {
 for (int i = 0; i < 10; ++i) {
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  std::cout << c;
 }
 };
 
 std::cout << "with launch::async:\n";
 std::future<void> foo = std::async(std::launch::async, print_ten, '*', 100);
 std::future<void> bar = std::async(std::launch::async, print_ten, '@', 200);
 // async "get" (wait for foo and bar to be ready):
 foo.get(); // 注：注释掉此句，也会输出'*'
 bar.get();
 std::cout << "\n\n";
 
 std::cout << "with launch::deferred:\n";
 foo = std::async(std::launch::deferred, print_ten, '*', 100);
 bar = std::async(std::launch::deferred, print_ten, '@', 200);
 // deferred "get" (perform the actual calls):
 foo.get(); // 注：注释掉此句，则不会输出'**********'
 bar.get();
 std::cout << '\n';
 
 return 0;
}
 
///
// reference: https://en.cppreference.com/w/cpp/thread/async
std::mutex m;
 
struct X {
 void foo(int i, const std::string& str) {
 std::lock_guard<std::mutex> lk(m);
 std::cout << str << ' ' << i << '\n';
 }
 void bar(const std::string& str) {
 std::lock_guard<std::mutex> lk(m);
 std::cout << str << '\n';
 }
 int operator()(int i) {
 std::lock_guard<std::mutex> lk(m);
 std::cout << i << '\n';
 return i + 10;
 }
};
 
template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
 auto len = end - beg;
 if (len < 1000)
 return std::accumulate(beg, end, 0);
 
 RandomIt mid = beg + len / 2;
 auto handle = std::async(std::launch::async, parallel_sum<RandomIt>, mid, end);
 int sum = parallel_sum(beg, mid);
 return sum + handle.get();
}
 
int test_async_3()
{
 std::vector<int> v(10000, 1);
 std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
 
 X x;
 // Calls (&x)->foo(42, "Hello") with default policy:
 // may print "Hello 42" concurrently or defer execution
 auto a1 = std::async(&X::foo, &x, 42, "Hello");
 // Calls x.bar("world!") with deferred policy
 // prints "world!" when a2.get() or a2.wait() is called
 auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
 // Calls X()(43); with async policy
 // prints "43" concurrently
 auto a3 = std::async(std::launch::async, X(), 43);
 a2.wait();           // prints "world!"
 std::cout << a3.get() << '\n'; // prints "53"
 
 return 0;
} // if a1 is not done at this point, destructor of a1 prints "Hello 42" here
 
///
// reference: https://thispointer.com/c11-multithreading-part-9-stdasync-tutorial-example/
int test_async_4()
{
 using namespace std::chrono;
 
 auto fetchDataFromDB = [](std::string recvdData) {
 // Make sure that function takes 5 seconds to complete
 std::this_thread::sleep_for(seconds(5));
 //Do stuff like creating DB Connection and fetching Data
 return "DB_" + recvdData;
 };
 
 auto fetchDataFromFile = [](std::string recvdData) {
 // Make sure that function takes 5 seconds to complete
 std::this_thread::sleep_for(seconds(5));
 //Do stuff like fetching Data File
 return "File_" + recvdData;
 };
 
 // Get Start Time
 system_clock::time_point start = system_clock::now();
 
 std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
 
 //Fetch Data from File
 std::string fileData = fetchDataFromFile("Data");
 
 //Fetch Data from DB
 // Will block till data is available in future<std::string> object.
 std::string dbData = resultFromDB.get();
 
 // Get End Time
 auto end = system_clock::now();
 auto diff = duration_cast <std::chrono::seconds> (end - start).count();
 std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
 
 //Combine The Data
 std::string data = dbData + " :: " + fileData;
 //Printing the combined Data
 std::cout << "Data = " << data << std::endl;
 
 return 0;
}
 
} // namespace future_

