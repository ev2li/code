#include <iostream>
#include <string>
using namespace std;

void test01(){
        string str = "hello";

        //1.插入
        str.insert(1, "efg");
        cout << "str = " << str << endl;

        //2.删除
        str.erase(1, 3);
        cout << "str = " << str << endl;
}

int main(){
        test01();
        return 0;
}