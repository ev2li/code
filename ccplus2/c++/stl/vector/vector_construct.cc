#include <iostream>
#include <vector>
using namespace std;

/*
        @brief
        vector是可以动态扩展的
 */

void printVector(vector<int>& v){
        for(auto it = v.begin(); it != v.end(); it++){
                cout << *it << endl;
        }
}

void test01(){
         //1.默认构造
        vector<int> v1;
        for(int i = 0; i < 10; i++){
                v1.push_back(i);
        }

       printVector(v1);

        //2.通过区间的方式进行构造
       vector<int> v2(v1.begin(), v1.end());
       printVector(v2);

        //3. 通过n个element
        vector<int> v3(10, 100);
        printVector(v3);

        //4. 拷贝构造
        vector<int> v4(v3);
        printVector(v4);
}

int main(){
        test01();
        return 0;
}