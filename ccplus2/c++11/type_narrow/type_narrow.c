#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int a = 1024;
    char b = a; //ok数据丢失  最大127  
    printf("b = %d\n", b);
    return 0;
}
