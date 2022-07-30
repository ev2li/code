#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* init(){ //指针函数
    // char str[32] = { 0 };
    char* str = (char*)malloc(128);
    return str; //不能返回局部变量的地址
}

int main(){
    char* s = init();
    strcpy(s, "hello");
    printf("%s \n", s);
    free(s);
    return 0;
}