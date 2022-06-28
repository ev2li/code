#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    @brief
    1.find查找元素
    2.find_if按条件查找元素
    3.adjacent_find 查找相邻重复元素
    4.binary_search二分查找 
    5.count 统计元素个数
    6.count_if按条件统计元素个数 
*/

void printVector(const std::vector<int>& v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
}

void test01(){
        std::vector<int> v;
        for (size_t i = 0; i < 10; i++) {
                v.push_back(i);
        }
        printVector(v);

        auto it = std::find(v.begin(), v.end(), 4);
        if(it != v.end()){
                std::cout << "有" << std::endl;
        }else{
                std::cout << "没有" << std::endl;
        }
}

int main(){
        test01();
        return 0;
}