#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init(char** s){
    *s = (char*)malloc(sizeof(char) * 128);
}

int main(){
    char* str = NULL;
    init(&str);
    strcpy(str, "hello");
    printf("%s \n", str);
    return 0;
}