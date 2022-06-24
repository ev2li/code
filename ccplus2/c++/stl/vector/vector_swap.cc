#include <iostream>
#include <vector>
using namespace std;

/*
    @brief
    vector容器的互换
    1.基本的使用
    2.实际的用途
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
        for(int i = 0; i < 10; i++){
                v1.push_back((i + 1) * 10);
        }
        printVector(v1);

        vector<int> v2;
        for(int i = 10; i > 0; i--){
                v2.push_back((i) * 10);
        }
        printVector(v2);

        cout << "交换后" << endl;

        v1.swap(v2);
        printVector(v1);       
        printVector(v2);       
}

//实际用途，巧用swap可以收缩内存空间
void test02(){
        vector<int> v;
        for(int i = 0; i < 100000; i ++){
                v.push_back(i);
        }

        cout  <<  "v的容量:" << v.capacity() << endl;
        cout  <<  "v的大小:" << v.size() << endl;

        v.resize(3); //重新指定大小
        cout  <<  "v的容量:" << v.capacity() << endl;
        cout  <<  "v的大小:" << v.size() << endl;

        //巧用swap收缩内存 vector<int>(v):匿名对象 .swap(v) 容器的交换
        vector<int>(v).swap(v); 
        cout  <<  "v的容量:" << v.capacity() << endl;
        cout  <<  "v的大小:" << v.size() << endl;
 }

int main(){
        // test01();
        test02();
        return 0;
}