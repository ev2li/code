#include <iostream>
#include <vector>
using namespace std;

/*
    @brief: vector容器的容量和大小操作
*/

void printVector(vector<int>& v){
        for(auto it = v.begin(); it != v.end(); it++){
                cout << *it << " ";
        }
        cout << endl;
}

void test01(){
        vector<int> v1;
        for(int i = 0; i < 10; i++){
                v1.push_back(i);
        }
        printVector(v1);

        if(v1.empty()){ //容器为空
                cout << "v1为空"  << endl;
        }else{
                cout << "v1不为空"  << endl;
                cout << "v1的容量:" <<  v1.capacity()  << endl;
                cout << "v1的大小:"  << v1.size() << endl;
        }

        //重新指定大小
        v1.resize(15, 100); //利用重载的版本，可以指定默认的填充值，参数2
        printVector(v1); //如果重新指定的比原来长，默认用0填充新的位置

        v1.resize(5);
        printVector(v1); //如果重新指定的比原来短了超出的会删掉
}

int main(){
        test01();
        return 0;
}