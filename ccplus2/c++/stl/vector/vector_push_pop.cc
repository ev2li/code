#include <iostream>
#include <vector>
using namespace std;

/*
    @brief
    vector的插入和删除
*/

void printVector(vector<int>& v){
        if(v.empty()){
                cout << "要输出的容器为空" << endl;
                return;
        }

        for(auto it = v.begin(); it != v.end(); it++){
                cout << *it << " ";
        }
        cout << endl;
}

void test01(){
        vector<int> v1;
        for(int i = 0; i < 5; i++){
                v1.push_back((i + 1) * 10);
        }

        printVector(v1);

        //尾删
        v1.pop_back();
        printVector(v1);        

        //插入 第一个参数是迭代器
        v1.insert(v1.begin(), 100);
        printVector(v1);

        //插入 第一个参数是迭代器
        v1.insert(v1.begin(), 2, 1000);
        printVector(v1);       

        //删除 参数也是迭代器
        v1.erase(v1.begin());
        printVector(v1); 

        //删除
        // v1.erase(v1.begin(), v1.end()); //相当于清空
        v1.clear(); //清空
        printVector(v1);      
}

int main(){
        test01();
        return 0;
}