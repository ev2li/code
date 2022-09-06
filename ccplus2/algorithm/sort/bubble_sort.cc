#include <iostream>
using namespace std;

/*
    @brief 冒泡排序
*/

void bubbleSort(){
    int a[6] = {6 , 8, 11 ,4, 2, 1};
    int length = 6;
    int max = length - 1;
    for(int i = max ; i > 0; i--){
        for(int j = 0; j < i ;j++){
            if(a[j] > a[j + 1]){
                int tmp = a[j + 1];
                a[j+1] = a[j];
                a[j] = tmp;
             }
        }
    }

    for(int m = 0;m < length;m++){
        std::cout << a[m] << std::endl;
    }
}

int main(){
    bubbleSort();
    return 0;
}