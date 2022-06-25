#include <iostream>
#include <deque>

using namespace std;

/*
    @brief deque赋值
*/

void printDeque(const std::deque<int>& dq){
        for (auto it = dq.begin(); it != dq.end(); it++) {
                        //*it = 100; 容器的迭代器是只读的,不可以修改
                        cout << *it << " ";
        }
        cout << endl; 
}

void test01(){
        deque<int> dq;
        for (int i = 0; i < 10; i++) {
                dq.push_back(i);
        }
        printDeque(dq);

        //operator= 赋值
        deque<int> d2;
        d2 = dq;
        printDeque(d2);

        //assign赋值
        deque<int> d3;
        d3.assign(dq.begin(), dq.end());
        printDeque(d3);

        deque<int> d4;
        d4.assign(10, 100);
        printDeque(d4);
}

int main(){
        test01();
        return 0;
}