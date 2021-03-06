#include <iostream>
#include <vector>
using namespace std;

/*
    @brief
    vector容器的数据存取
*/

void test01(){
        vector<int> v1;
        for(int i = 0; i < 10; i++){
                v1.push_back((i + 1) * 10);
        }

        //利用[]方式来访问数组中元素
        for(int i = 0; i < v1.size(); ++i){
                cout << v1[i] << " ";
        }
        cout << endl;

        //利用at方式来访问数组中元素
        for(int i = 0; i < v1.size(); ++i){
                cout << v1.at(i) << " ";
        }
        cout << endl;

        //获取第一个元素
        cout << "第一个元素:" << v1.front() << endl;

        //获取最后一个元素
        cout << "最后一个元素:" << v1.back() << endl;
}

int main(){
        test01();
        return 0;
}