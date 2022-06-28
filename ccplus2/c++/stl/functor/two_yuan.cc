#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
    @brief 二元谓词 返回值为bool的两个参数 是二元谓词 pred
*/

void printVector(const std::vector<int>& v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
}


struct MyCompare{
public:
        bool operator()(int va, int vb){
                return va > vb;
        }
};

void test01(){
        std::vector<int> v;
        v.push_back(10);
        v.push_back(40);
        v.push_back(30);
        v.push_back(50);
        v.push_back(20);

        sort(v.begin(), v.end());
        printVector(v);

        //使用函数对象，改变算法策略，变为子降序排序
        sort(v.begin(), v.end(), MyCompare());
        printVector(v);
}

int main(){
        test01();
        return 0;
}