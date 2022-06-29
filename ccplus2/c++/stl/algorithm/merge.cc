#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    @brief
*/

void printVector(const std::vector<int>& v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
}

void test01(){
        std::vector<int> v;
        std::vector<int> v2;
        std::vector<int> v3;

        for (size_t i = 0; i < 10; i++) {
                v.push_back(i);
                v2.push_back(i  + 1);
        }
        v3.resize(v.size()+ v2.size());
        std::merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
        printVector(v3);
}

int main(){
        test01();
        return 0;
}