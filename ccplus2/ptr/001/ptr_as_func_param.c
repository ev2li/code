#include <stdio.h>

void swap(int *a, int *b){
    int *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;    
}

void swap_with_third_var(int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void swap_use_xor(int* x, int *y){
    *x = *x ^ *y;
    *y = *y ^ *x;
    *x = *x ^ *y;
}

int main(){
    int a = 1;
    int b = 2;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    a = 100;
    b = 200;
    swap_with_third_var(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    a = 10;
    b = 20;
    swap_use_xor(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}