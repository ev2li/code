#include <iostream>
#include <deque>
using namespace std;

/*
    @brief
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

        //1.通过[]方式访问
        for (int i = 0; i < d1.size(); i++) {
                cout << d1[i] << " ";
        }
        cout  << endl;

        //2.通过at的方式访问
        for (int i = 0; i < d1.size(); i++) {
                cout << d1.at(i) << " ";
        }

        //3.访问头元素
        cout << "第一个元素" << d1.front()  << endl;

        //4.访问尾元素
        cout << "最后一个元素: " << d1.back() << endl;
        cout  << endl;
}

int main(){
        test01();
        return 0;
}