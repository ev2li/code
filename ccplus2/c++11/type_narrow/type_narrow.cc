#include<iostream>
using namespace std;

int main(int argc, char **argv)
{
    int a  = 1024;
    char  b = {a}; //防止类型收窄

    cout  <<  b << endl;
    return 0;
}
