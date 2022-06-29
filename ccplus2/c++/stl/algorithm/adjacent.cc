#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    @brief adjacent 相邻重复
*/
void printVector(const std::vector<int>& v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
}

void test01(){
        std::vector<int> v;
        v.push_back(0);
        v.push_back(2);
        v.push_back(3);
        v.push_back(0);
        v.push_back(4);
        v.push_back(5);
        v.push_back(5);

        printVector(v);

        auto it = std::adjacent_find(v.begin(), v.end());
        if(it == v.end()){
                std::cout << "未找到相邻重复元素" << std::endl;
        }else{
                 std::cout << "找到相邻重复元素" << *it << std::endl;
        }
}

int main(){
        test01();
        return 0;
}