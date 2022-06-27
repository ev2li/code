#include <iostream>
#include <stack>
using namespace std;

/*
    @brief
*/

void printStack(std::stack<int>& s){
        while(!s.empty()){
                //查看栈顶的元素
                std::cout << "栈顶元素为:" << s.top() << endl;
               
               //出栈
               s.pop();
        }

        std::cout << "栈的大小" << s.size() << endl;
}

void test01(){
        std::stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        printStack(s);
}

int main(){
        test01();
        return 0;
}