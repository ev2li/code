#include <iostream>
#include <string>
using namespace std;

void test01(){
        string s1 = "abcdefg";
        int pos = s1.find("df"); //没有的时候返回-1
        if(pos == -1){
                cout << "未找到字符串" << endl;
        }else{
                cout << "找到了:" << pos << endl;
        }

        //rfind
        pos = s1.rfind("de");
        if(pos == -1){
                cout << "未找到字符串" << endl;
        }else{
                cout << "找到了:" << pos << endl;
        }

        //rfind和find的区别，rfind从右向左，find从左向右
}

void test02(){
        string str = "abcdefg";

        str.replace(1, 3, "xyzx");

        cout << str << endl;

}

int main(){
        test01();
        test02();
        return 0;
}