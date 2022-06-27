#include <iostream>
#include <set>
using namespace std;

/*
    @brief set插入insert earse删除
*/

void printSet(const std::set<int> l){
        for(auto it = l.begin(); it != l.end(); it++){
                std::cout << (*it) << " ";
        }
        std::cout << std::endl;
}

void test01(){
        std::set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(4);

        printSet(s);
        s.erase(s.begin());

        s.erase(4);
        printSet(s);

}

int main(){
        test01();
        return 0;
}