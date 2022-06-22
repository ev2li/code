#include "class_template_detach.hpp"

void test01(){
        Person<string, int> p("Tom", 20);
        p.showPerson();
}

int main(){
        test01();
        return 0;
}