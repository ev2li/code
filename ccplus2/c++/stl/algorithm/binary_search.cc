#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    @brief 二分查找 ，必须是有序的序列
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
       auto it =  std::binary_search(v.begin(), v.end(), 3);

        if(it){
                std::cout << "找到了"  << std::endl;
        }else{
                std::cout << "没找到"  << std::endl;
        }
}

int main(){
        test01();
        return 0;
}