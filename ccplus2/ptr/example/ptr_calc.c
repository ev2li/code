#include <stdio.h>

void Mystrcpy(char *dest, const char *src){
    while ((*dest++ = *src++)  != '\0');
}

int main(){
    int x = 3, y = 0, *px = &x;
    y = *px + 5;
    y = ++*px;
    printf("%d\n", y);
    y = (*px)++;
    printf("%d\n", y);

    char s1[32] = "hello";
    char s2[32] = "123456789";
    Mystrcpy(&s2, &s1);
    printf("%s\n", s2);
    return 0;
}