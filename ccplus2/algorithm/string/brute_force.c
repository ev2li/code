#include <stdio.h>

//bruteForce
char* StrStr(const char *str, const char *target){
    if(!*target){
        return str;
    }
    char *p1 = (char*)str; //把字符串第一位赋值给p1
    while(*p1){
        char *p1Begin = p1, *p2 = (char*)target;
        while(*p1 && *p2 && *p1 == *p2){
            p1++;
            p2++;
        }
        if(!*p2){ //这个是到了p2的结尾 和'\0'进行比较
            return p1Begin;
        }
        p1 = p1Begin + 1; //p1Begin往后移一位
    }
    return NULL;
}

/** 
  * RabinKarp: 
  * 将每一个匹配子串映射成为一个hash值，例如，将子串看做一个多进制数，比较它的值与母串中相同
  * 长度子串中的hash值，如果相同，再细致地按字符确认字符串是否确实相同，顺序计算母串hash值的
  * 过程中，使用增量计算的方法，扣除最高位的hash值，增加最低位的hash值，因此能在平均情况下做到
  * O(m+n)
**/

int main(){
    
    return 0;
}