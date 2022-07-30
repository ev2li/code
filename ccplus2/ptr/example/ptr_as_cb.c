#include <stdio.h>

typedef int (*T)(int,int);

int less(int x, int y){
    return (x > y) ? 1 : 0;
}

int greater(int x, int y){
    return (x < y) ? 1 : 0;
}

void sort(int *a, int length, T cb){
    int i,j;
    for(i = 0;i < length - 1;i++){
        for(j = 0; j < length - i -1 ;j++){
            // if (a[j] > a[j + 1]){
            if(cb(a[j], a[j + 1])){
                int num = a[j];
                a[j] = a[j + 1];
                a[j + 1] = num;
            }
        }
    }
}

int main(){
    int a[10] = { 0 };
    int i;
    for(i = 0;i < 10;i++){
        scanf("%d", &a[i]);
    }
    sort(a, 10, less);
    for(i = 0;i < 10;i++){
        printf("%d ", a[i]);
    }
    return 0;
}