#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

/*
    @brief 关系仿函数 
    equal_to等于
    not_equal_to 不等于
    greater 大于
    greater_equal 大于等于
    less小于
    less_equal 小于等于
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
        v.push_back(30);
        v.push_back(50);
        v.push_back(40);
        v.push_back(20);

        printVector(v);

        // sort(v.begin(), v.end(), MyCompare());
        sort(v.begin(), v.end(), std::greater<int>()); //内建的函数对象
        printVector(v);


}

int main(){
        test01();
        return 0;
}