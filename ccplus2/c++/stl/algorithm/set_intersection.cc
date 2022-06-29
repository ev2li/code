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
        std::vector<int> v1;
        std::vector<int> v2;
        std::vector<int> v3;

        for (size_t i = 0; i < 10; i++) {
                v1.push_back(i);
                v2.push_back(i  + 5);
        }

        v3.resize(std::min(v1.size(), v2.size()));
        std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
        printVector(v3);
}

int main(){
        test01();
        return 0;
}