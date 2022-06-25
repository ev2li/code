#include <iostream>
#include <iostream>
#include <deque>
using namespace std;

/*
    @brief deque是端数组（deque容器的迭代器也是支持随机访问的）
    deque和vector的区别
    1.vector对于头部的插入和删除效率低，数据量越大，效率越低
    2.deque相对而言，对头部的插入删除速度会比vector快
    3.vector访问元素的速度会比deque快
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
        for (size_t i = 0; i < 10; i++) {
            d1.push_back(i);
        }
        printDeque(d1);

        deque<int> d2(d1.begin(), d1.end());
        printDeque(d2);

        deque<int> d3(10, 100);
        printDeque(d3);

        deque<int> d4(d3);
        printDeque(d4);
}

int main(){
        test01();
        return 0;
}