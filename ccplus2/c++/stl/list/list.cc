#include <iostream>
#include <list>

using namespace std;

/*
    @brief list头尾都能插入和删除 
    push_back push_front
    pop_back pop_back
    insert(pos, elem)
    insert(pos, n, elem)
    earse(pos)
    remove(elem)
*/

void printList(const std::list<int> l){
        for(auto it = l.begin(); it != l.end(); it++){
                std::cout << (*it) << " ";
        }
        std::cout << std::endl;
}

void test01(){
        std::list<int> l1;

        l1.push_back(10);
        l1.push_back(20);
        l1.push_back(30);
        l1.push_back(40);

        printList(l1);

        std::list<int> l2(l1.begin(), l1.end());
        printList(l2);

        std::list<int> l3(l2);
        printList(l3);

        std::list<int> l4(4, 100);
        printList(l4);

        std::list<int> l5;
        l5 = l4;
        printList(l5);

        l5.swap(l1);
        printList(l5);
        printList(l1);

        l5.remove(30);
        printList(l5);       
}

int main(){
        test01();
        return 0;
}