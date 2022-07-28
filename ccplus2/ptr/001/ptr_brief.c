#include <stdio.h>

int main(){
    int num = 1;
    int *p = &num;
    *p = 100;
    printf("%d\n", num);

    char ch = 'a';
    // int *q = &ch; 类型不兼容
    char *q = &ch;
    *q = 'x'; 
    printf("%c\n", ch);

    printf("%p\n", p);
    printf("%p\n", q);
    printf("%p\n", p+1); //步长
    printf("%p\n", q+1);

    return 0;
}