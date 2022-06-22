#include <iostream>
#include "myArray.hpp"
#include <string>

using namespace std;

/*
        实现通用数组模板类：
        1.可以对内置数据类型以及自定义数据类型的数据进行存储
        2.将数组中的数据存储到堆区
        3.构造函数中可以传入数组的容量
        4.提供对应的拷贝构造函数以及operator=防止浅拷贝问题
        5.提供尾插法和尾删法对数组中的数据进行增加和删除
        6.可以通过下标的方式访问数组中的元素
        7.可以获取数组中当前元素个数和数组的容量
*/

void printArray(MyArray<int>&  arr){
        for(int i = 0; i < arr.getSize(); i++){
                cout << arr[i] << " ";
        }
        cout << endl;
}

void test01(){
        MyArray<int> arr1(5);
        MyArray<int> arr2(arr1);
        MyArray<int> arr3(100);
        arr3 = arr1;

        for(int i = 0; i < 5; i++ ){
                arr1.Push_Back(i); //尾插法测试
        }

        cout << "arr1的打印输出为:" << endl;
        printArray(arr1);

        cout << "arr1的容量:" << arr1.getCapacity() << endl;
        cout << "arr1的大小:" << arr1.getSize() << endl;

        printArray(arr2);
        arr2.Pop_Back();
        cout << "arr2尾删后输出:" << endl;
        cout << "arr2的容量:" << arr2.getCapacity() << endl;
        cout << "arr2的大小:" << arr2.getSize() << endl;
}


//测试自定义数据类型
class Person{
public:
        Person(){}
        Person(string name, int age){
                this->m_name = name;
                this->m_age = age;
        }
public:
        string m_name;
        int m_age;
};

void printPersonArray(MyArray<Person>& arr){
        for(int i = 0; i < arr.getSize(); i++){
                cout << "姓名:" << arr[i].m_name << ",年龄: " << arr[i].m_age << endl;
        }
}

void test02(){
        MyArray<Person> arr(10);
        Person p1("张三", 99);
        Person p2("李四", 20);
        Person p3("王五", 39);
        Person p4("赵六", 49);

        arr.Push_Back(p1);
        arr.Push_Back(p2);
        arr.Push_Back(p3);
        arr.Push_Back(p4);

        printPersonArray(arr);

        //输出容量和大小
        cout << "arr容量:" << arr.getCapacity() << endl;
        cout << "arr大小:" << arr.getSize() << endl;
}

int main(){
        test01();
        test02();
        return 0;
}