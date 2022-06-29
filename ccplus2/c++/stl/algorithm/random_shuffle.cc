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

        for (size_t i = 0; i < 10; i++) {
                v.push_back(i);
        }

        std::random_shuffle(v.begin(), v.end());
        printVector(v);
}

int main(){
        test01();
        return 0;
}