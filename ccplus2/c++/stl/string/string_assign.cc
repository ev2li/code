#include <iostream>
#include <string>
using namespace std;


void test01(){
        string s1 = "Hello World";
        string s2 = s1;
        cout << s2 << endl;
        
        string s3;
        s3.assign("Hello c++");
        cout << s3 << endl;

        string s4;
        s4.assign(s2, 3);
        cout << s4 << endl;

        string s5;
        s5.assign(s3);
        cout << s5 << endl;

        string s6;
        s6.assign(10, 'b');
        cout << s6 << endl;
}

int main(){
        test01();
        return 0;
}