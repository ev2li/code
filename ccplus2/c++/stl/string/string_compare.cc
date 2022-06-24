#include <iostream>
#include <string>
using namespace std;

void test01(){
        string str1 = "abc";
        string str2 =  "xbc";

        int ok = str1.compare(str2);
        if(ok == 0){
                cout << "相等" << ok << endl;
        }else if(ok > 0 ){
                cout << "大于" << ok << endl;
        }else{
                cout << "小于" << ok << endl;
        }
}

int main(){
        test01();        
        return 0;
}