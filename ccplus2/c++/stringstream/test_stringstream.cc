#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
    @brief
*/

//用于类型转换
void test01(){
    std::stringstream ss;
    std::string strResult;
    int nValue = 1000;

    ss << nValue;
    ss >> strResult;
}

//多字符串拼接
void test02(){
    std::stringstream ss;
    ss << "first" << " " << "string" ;
    ss << " second string";

    //可以使用str()方法，将stringstream类型转换为string类型
    std::cout << "str result is:"  << ss.str()<< std::endl;

    //以下都是用于清空流
    ss.str("");
    ss.clear();
    std::cout << "str result is:"  << ss.str()<< std::endl;
}

int main(){
    test01();
    test02();
    return 0;
}