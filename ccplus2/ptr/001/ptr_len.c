#include <stdio.h>

int main(){
    printf("%lu\n",sizeof(int*));
    printf("%lu\n",sizeof(char*));
    printf("%lu\n",sizeof(double*));
    printf("%lu\n",sizeof(float*));
    printf("%lu\n",sizeof(short*));
    
    char ch = 'a';
    char *q = &ch;
    printf("%lu\n",sizeof(ch));
    printf("%lu\n",sizeof(q));
    return 0;
}