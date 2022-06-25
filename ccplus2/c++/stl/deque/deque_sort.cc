#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
    @brief  deque的排序
*/

void printDeque(const std::deque<int>& dq){
        for (auto it = dq.begin(); it != dq.end(); it++) {
                        //*it = 100; 容器的迭代器是只读的,不可以修改
                        cout << *it << " ";
        }
        cout << endl; 
}

void test01(){
        deque<int> d1;
        d1.push_back(10);
        d1.push_back(20);
        d1.push_front(30);
        printDeque(d1);
        
        //排序 对于支持随机访问的迭代器的容器，都可以利用sort算法进行排序  
        sort(d1.begin(), d1.end()); //默认是升序
        printDeque(d1);
}

int main(){
        test01();
        return 0;
}