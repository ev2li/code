#include <iostream>
#include <string>
using namespace std;

/*
        @brief:
        1.char* 是一个指针
        2.string是一个类，类内部封装了一个char*，来管理这个字符串，是一个char*的容器

        @特点：
        1.find,copy,delete,replace,insert
*/
void test01(){
        string s1;
        const char* str = "Hello World";
        string s2(str);
        cout << s2 << endl;
        string s3(s2);
        cout << s3<< endl;

        string s4(10, 'a');
        cout << s4 << endl;
}

int main(){
        test01();        
        return 0;
}