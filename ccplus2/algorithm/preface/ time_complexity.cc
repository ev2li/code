#include <iostream>
#include <sys/time.h>
using namespace std;

//获取毫秒数
unsigned long long getSecond();

void sum1(int n);
void sum2(int n);
void sum3(int n);
void sum4(int n);
int sum5(int n);
void sum6(int n);

int main(){
    unsigned long long start = getSecond();
    // sum1(1000000); //线性阶O(n)
    // sum2(1000000); //常数阶O(1)
    // sum3(100); //平方阶O(n^2)
    sum4(100); //对数阶O(log n)
    unsigned long long end = getSecond();
    std::cout << end - start << std::endl;
    return 0;
}

//2n+2(O(n))
void sum1(int n){
    int total = 0;
    int  i;
    for(i = 0;i <= n; i++){
        total += i;
    }
    std::cout <<  total << std::endl;
}

//O(log n)
void sum2(int n){
    std::cout << n * (n+1) / 2 << std::endl;
}

// n + n * n (平方阶O(n ^ 2))
void sum3(int n){
    int total = 0;
    int total2 = 0;
    for(int i = 0; i <=n; i++){
        total += i;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            total2 += j;
        }
    }
}


// O(log n)
void sum4(int n){
    int i = 1;
    while(i <= n){
        i = i * 2;
    }
}

//斐波那契数列前n项和
int sum5(int n){
    if(n < 2){
        return n;
    }
    return sum5(n - 1) + sum5(n - 2);
}

//O(n^2)
void sum6(int n){
    int total = 0;
    for(int i = 0;i <= n;i++){
        for(int j = 0; j <= i; j++){
            total += i;
        }
    }
}

unsigned long long getSecond(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
}