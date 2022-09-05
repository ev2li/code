#include <stdio.h>

void *memmove(void *dest, const void *src, size_t n){
    char *p1 = dest;
    const char *p2 = src; //常量

    if(p2 < p1){
        p2 += n;
        p1 += n;
        while(n-- != 0){
            *--p1 = *--p2;
        }
     }else{
        while(n--  != 0){
            *p1++ = *p2++;
        }
     }
     return p1;
}

int main(){
    
    return 0;
}