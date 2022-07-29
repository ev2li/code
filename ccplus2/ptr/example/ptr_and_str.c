#include <stdio.h>

int main(){
    char* str[] = {" I love China!", " I am"};
    printf("%p \n", str); //str是数组的首地址 是一个char* 类型的数组(指针数组)
    printf("%s \n", str[0]);
    return 0;
}