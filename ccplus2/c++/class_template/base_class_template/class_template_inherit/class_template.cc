#include <iostream>
using namespace std;

/*
        类模板与继承
*/

template<class T>
class Base{
public:
        T m;
};

//class Son : public Base{ //err 必须要知道父类中的T的数据类型，才能继承给子类
class Son : public Base<int>{

};

void test01(){
        Son s1;
}

//如果想灵活的指定父类中T的类型，子类也需要变成类模板
template<class T1, class T2>
class Son2:public Base<T2>{
public:
        Son2(){
                cout << "T1的类型:" << typeid(T1).name() << endl;
                cout << "T2的类型:" << typeid(T2).name() << endl;
        }
public:
        T1 obj;
};

void test02(){
        Son2<int, char> s2;
}

int main(){
        test01();
        test02();
        return 0;
}