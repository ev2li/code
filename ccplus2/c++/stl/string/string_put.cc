#include <iostream>
#include <string>
using namespace std;

/*
        @brief 字符串的存取
*/
void test01(){
        string str = "Hello";
        cout << "str = " << str << endl;

        //1.通过[]来访问单个字符
        for(int i = 0; i < str.size(); i++){
                cout << str[i] << " ";
        }
        cout << endl;

        //2.通过at()来访问单个字符 
        for(int i = 0; i < str.size(); i++){
                cout << str.at(i) << " ";
        }
        cout << endl;

        //修改单个字符
        str[0] = 'x';
        cout << "str = " << str << endl;

        str.at(3) = 'y';
        cout << "str = " << str << endl;
}

int main(){
        test01();
        return 0;
}