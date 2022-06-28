#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    @brief
    算法主要由头文件<algorithm> <functional> <numeric>组成
*/

void MyPrint(int v){
        std::cout << v << " ";
}

void printVector(const std::vector<int>& v){
       std::for_each(v.begin(), v.end(), MyPrint);
}

class MyPrint01
{
public:
        void operator()(int v){
                std::cout << v << " ";
        }
};

void test01(){
        std::vector<int> v;
        for (size_t i = 0; i < 10; i++) {
                v.push_back(i);
        }
        printVector(v);
        std::cout << std::endl;
        std::for_each(v.begin(), v.end(), MyPrint01());
}

int main(){
        test01();
        return 0;
}