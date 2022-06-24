#include <iostream>
#include <vector>
using namespace std;

/*
    @brief
    vector预留空间
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
        vector<int> v;
        int num = 0; //统计开辟次数
        int *p = NULL;
        for(int i = 0; i < 100000; i++){
                v.push_back(i);
                if(p != &v[0]){
                        p = &v[0];
                        num++;
                }
        }
        cout << "num = " << num << endl;
}

int main(){
        test01();
        return 0;
}