#include <iostream>
#include <deque>
using namespace std;

/*
    @brief deque的插入和删除
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

        //尾删
        d1.pop_back();

        //头删
        d1.pop_front();
        printDeque(d1);
}

void test02(){
        deque<int> d1;
        d1.push_back(10);
        d1.push_back(20);
        d1.push_front(100);
        d1.push_front(200);

        printDeque(d1);
        d1.insert(d1.begin(), 1000);
        printDeque(d1);

        d1.insert(d1.begin(), 2, 10000);
        printDeque(d1);       
}

void test03(){

        deque<int> d1;
        d1.push_back(10);
        d1.push_back(20);
        d1.push_front(100);
        d1.push_front(200);

        deque<int> d2;
        d2.push_back(1);
        d2.push_back(2);
        d2.push_back(3);

        d1.insert(d1.begin(), d2.begin(), d2.end());
        printDeque(d1);
}

void test04(){
        deque<int> d1;
        d1.push_back(10);
        d1.push_back(20);
        d1.push_front(100);
        d1.push_front(200);

        d1.erase(d1.begin());
        printDeque(d1);

        deque<int>::iterator it = d1.begin();
        it++;
        d1.erase(it);
        printDeque(d1);

        //按区间的方式删除
        // d1.erase(d1.begin(), d1.end());

        //清空
        d1.clear();
        printDeque(d1);
}

int main(){
        // test01();

        // test02();
        // test03();
        test04();
        return 0;
}