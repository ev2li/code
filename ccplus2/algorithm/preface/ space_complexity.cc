#include <iostream>
#include <sys/time.h>
#include <map>
#include <string>

//获取毫秒数
unsigned long long getSecond();

void sum1(int n);
void sum2(int n);
void sum3(int n);


int main(){
    unsigned long long start = getSecond();
    // sum1(1000000); //O(1)
    // sum2(100); //常数阶O(n)
    sum3(100); //常数阶O(1)
    unsigned long long end = getSecond();
    std::cout << end - start << std::endl;
    return 0;
}

//O(1)
void sum1(int n){
    int total = 0;
    int  i;
    int a = 0;
    int b = 0;

    for(i = 0;i <= n; i++){
        total += i;
        a += i;
        b += i;
    }
    std::cout <<  total << std::endl;
}

//O(n)
void sum2(int n){
    std::map<int, int>aTmp;
    for(int i = 1; i <= n; i++){
        aTmp.insert(std::pair<int, int>(i, i));
    }

    std::cout << aTmp.size() << std::endl;
}

//O(n)
void sum3(int n){
    std::map<std::string, std::string> aTmp3;

    for(int i = 1; i <= n; i++){
        aTmp3.insert(std::pair<std::string, std::string>(to_string(i), to_string(i)));
    }

    std::cout << aTmp3.size() << std::endl;
}

unsigned long long getSecond(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
}