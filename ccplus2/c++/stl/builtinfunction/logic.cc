#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

/*
    @brief 逻辑仿函数 
    logic_and
    logic_or
    logic_not
*/

void printVector(const std::vector<bool>& v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
}

void test01(){
        std::vector<bool> v;
        v.push_back(true);
        v.push_back(false);
        v.push_back(true);
        v.push_back(false);

        printVector(v);
        //利用逻辑非，将容器v搬运到容器v2中，并执行取反操作
        std::vector<bool> v2;
        v2.resize(v.size());

        std::transform(v.begin(), v.end(), v2.begin(), std::logical_not<bool>());
        printVector(v2);
}

int main(){
        test01();
        return 0;
}