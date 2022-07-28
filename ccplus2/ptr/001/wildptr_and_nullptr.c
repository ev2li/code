#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p = NULL;
    //*p = 100; //segmentation fault(core dump):访问了不可访问的内存 wild pointer(野指针)
    //1.系统分配的内存
    int a;
    int *p1 = &a;
    //2.用户申请的堆内存
    char *p2 = (char*)malloc(32);
    printf("%p\n", p2);
    free(p2); //不释放会造成memory leak
    return 0;
}