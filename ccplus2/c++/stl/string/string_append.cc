#include <iostream>
#include <string>
using namespace std;


void test01(){
        string s1 = "abc";
        string s2 = s1 + "def";
        cout << s2 << endl;

        string s3;
        s3 = s2.append("xyz");
        cout << s3 << endl;

        string s4;
        s4.append(s3);
        cout << s4 << endl;

        string s5;
        s5.append(s4, 1, 5);
        cout << s5 << endl;

}

int main(){
        test01();
        return 0;
}