#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
        brief: vector容器存放内置数据类型
*/

void myPrint(int val){
        cout << val << endl;
}

void test01(){
        std::vector<int> v;

        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);

        for(auto it = v.begin(); it != v.end(); it++){
                cout <<  *it << endl;
        }

        for_each(v.begin(), v.end(), myPrint);
}

int main(){
        test01();
        return 0;
}