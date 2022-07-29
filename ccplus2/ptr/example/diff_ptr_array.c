#include <stdio.h>

int main(){
    char str[32] = "helloworld";
    char *p = "helloworld";
    // str++; 数组名是常指针
    p++; //指向下一下元素 e
    printf("&str:%p \n", str);
    printf("&p:%p \n", p);
    char * const q = "helloworld";
    // q++;
    str[0] = 'x';
    // p[0] = 'x'; //.rodata是只读数据区，是不能修改的(字符串常量)

    printf("%lu\n", sizeof(str)); //数组的长度
    printf("%lu\n", sizeof(p)); //指针的长度
    return 0;
}