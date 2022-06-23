#include <iostream>

using namespace std;

struct Test
{
    int a;
    int b;
    char name[50];
};

int	main(int argc, char **argv)
{
    struct Test  tmp = {1, 2, "mike"}; //列表初始化
    int a =  1;
    int b = {1}; //ok
    int c{2}; //ok
    int arr[] = {1, 2, 3};
    int arr[]{1, 2, 3};
    return 0;
}

