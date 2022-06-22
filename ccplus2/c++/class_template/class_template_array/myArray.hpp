#pragma once
#include <iostream>

using namespace std;

template<class T>
class MyArray{
public:
        MyArray(int capacity){
                cout << "MyArray有参构造调用" << endl;
                this->m_capacity = capacity;
                this->m_size = 0;
                this->pAddress = new T[this->m_capacity];
        }
        //拷贝构造
        MyArray(const MyArray& arr){
                cout << "MyArray拷贝构造调用" << endl;
                this->m_capacity = arr.m_capacity;
                this->m_size = arr.m_size;
                // this->pAddress = arr.pAddress;
               this->pAddress =  new T[arr.m_capacity]; //深拷贝

               //将arr中的数据都拷贝过来
               for(int i = 0; i < this->m_size; i++){
                        this->pAddress[i]  = arr.pAddress[i];
               }
        }

        //operator= 防止浅拷贝问题
        MyArray& operator=(){
                cout << "MyArray的operator调用" << endl;
                //先判断原来堆区是否有数据，如果有先释放
                if(this->pAddress != NULL){
                        delete[] this->pAddress;
                        this->pAddress = NULL;
                        this->m_capacity = 0;
                        this->m_size = 0;
                }

                //深拷贝
                this->m_capacity = arr.m_capacity;
                this->m_size = arr.m_size;
                this->pAddress = new T[arr.m_capacity];

                for(int i = 0; i < this->m_size; i++){
                        this->pAddress[i] = arr.pAddress[i]; 
                }
                return *this;
        }

        //尾插法
        void Push_Back(const T& val){
                //先判断容量是否等于大小
                if(this->m_capacity == this->m_size){
                        return;
                }

                this->pAddress[this->m_size] = val; //在数组的末尾插入数据
                this->m_size++; //更新数组的大小
        }

        //尾删法
        void Pop_Back(){
                //让用户访问不到最后一个元素即可，逻辑删除
                if(this->m_size == 0){
                        return;
                }
                this->m_size--;
        }

        //让用户可以通过下标的方式访问数组中的元素
        T& operator[](int index){
                if(index > this->m_size){
                        return;
                }

                return this->pAddress[i];
        }

        //获取数组的容量
        int getCapacity(){
                return this->m_capacity;
        }

        //获取数组的大小
        int getSize(){
                return this->m_size;
        }
        
        ~MyArray(){
                cout << "MyArray析构调用" << endl;
                if(this->pAddress != NULL){
                        delete[] this->pAddress;
                        this->pAddress = NULL;
                }
        }
private:
        T* pAddress; //指针指向堆区开劈的真实数组
        int m_capacity; //数组容量
        int m_size; //数组大小(元素个数)
};