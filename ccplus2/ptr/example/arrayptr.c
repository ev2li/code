#include <stdio.h>

int main(){
    int a[3][4] = {{1,2,3,4}, {2,3,4,5},{3,4,5,6}};
    int i, j;
/*     for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    } */

    //用数组指针来表示二维数组
    int(*p)[4] = a;
/*     
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            // printf("%d ", p[i][j]);
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
 */
    //用指针数组来表示二维数组
    int* q[3] = { a[0], a[1], a[2]};
    /*
    printf("%ld \n", sizeof(q));
    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        for(j = 0; j < sizeof(a[0])/sizeof(a[0][0]); j++){
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }
    */
    int *ptr = a[0];
    for(i = 0; i < 12; i++){
        // printf("%d ", *(ptr+i));
        printf("%d ", ptr[i]);
    }
    return 0;
}