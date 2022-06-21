#include <iostream>
using namespace std;

/*
        1.实现通用对数组进行排序的函数
        2.规则从大到小
        3.算法 选择
        4.测试 char数组 int数组
*/

template<class T>
void mySwap(T& a, T&b){
        T temp = a;
        a = b;
        b = temp;
}

template<class T>
void mySort(T arr[],  int len){
        for(int i = 0; i < len; i++){
                int max = i; //认定最大值
                for(int j = i + 1;  j < len;  j++ ){
                        if(arr[max] < arr[j]){
                                max = j;
                        }
                }
                if(max != i){
                        //交换max和i下标的元素
                        mySwap(arr[max], arr[i]);
                }
        }
}

//提供一个打印数组的模板
template<class T>
void printArray(T arr[], int len){
        for(int i = 0; i < len; i++){
                cout << arr[i] << " ";
        }
        cout << endl;
}

void test01(){
        //测试char数组
        char charArr[] = "badcfe";
        int num = sizeof(charArr) / sizeof(char);
        mySort(charArr,  num);
        printArray(charArr, num);
}

void test02(){
        int intArr[] = {7, 5, 1, 3, 9, 2, 4, 6, 8};
        int num = sizeof(intArr) / sizeof(int);
        mySort(intArr, num);
        printArray(intArr, num);
 }

int main(){
        test01();
        test02();  
        return 0;
}