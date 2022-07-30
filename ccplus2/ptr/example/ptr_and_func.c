#include <stdio.h>

void f1(){
    printf("hello world\n");
}

int add(int x, int y){
    return x + y;
}
typedef int(*T)(int, int); //声明一个新的类型T T表示函数指针类型
int main(){
    void (*p)(); //定义函数指针
    p = f1;
    p(); //通过函数指针调用函数
    // p = add; 类型不兼容
    int (*q)(int, int) = add;
    printf("%d \n", q(1, 2));
    T t = add; //等价于int(*T)(int, int)
    printf("%d \n", t(4, 5));
    return 0;
}