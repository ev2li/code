#include <iostream>
#include <deque>
using namespace std;

/*
    @brief deque容器大小,没有容量操作capacity()
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
        for (int i = 0; i < 10; i++) {
                d1.push_back(i);
        }
        printDeque(d1);

        if(d1.empty()){
                cout << "d1为空" << endl;
        }else{
                cout << "d1不为空"  << endl;
                cout << "d1的大小为:" << d1.size() << endl;
        }

        //重新指定大小
        // d1.resize(15);
        d1.resize(15,  1);
        printDeque(d1);

        d1.resize(5);
        printDeque(d1);
}

int main(){
        test01();
        return 0;
}