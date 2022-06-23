#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class MyString{
public:
    MyString(char *tmp = "abc"){ //普通构造函数
        len  = strlen(tmp);
        str = new char[len + 1]; //堆区申请空间
        strcpy(str, tmp); //拷贝内容
        cout << "普通构造函数" << tmp  << endl;
    }    

    MyString(const MyString &tmp){ //拷贝构造函数
        len = tmp.len;
        str  = new char[len + 1];
        strcpy(str, tmp.str);
        cout << "拷贝构造函数 tmp.str=" << tmp.str  << endl;
    }          

    //参数是非const的右值引用
    MyString(MyString  && t){
        len = t.len;
        str  = t.str;//拷贝地址,没有重新申请内存

        //原来指针置空
        t.str = NULL;
        cout << "移动构造函数" << endl;
    }  

    MyString &operator=(const MyString &tmp){ //赋值运算符重载
        if(&tmp == this){
            return *this;
        }
        //先释放原来的内存
        len = 0;
        delete []str;
        //重新申请内存
        len = tmp.len;
        str  = new char[len + 1];
        strcpy(str, tmp.str);   
        cout << "赋值运算符重载 tmp.str=" << tmp.str << endl;    
        return *this;
    }


    ~MyString(){ //析构函数
        if(str != NULL){
            delete []str;
            str = NULL;
            len = 0;
            cout << "已操作delete" << endl;
        }
    } 
private:
    char  *str = NULL;
    int len;
};

MyString func(){ //返回普通对象,不是引用,返回的是右值
    MyString obj("mike");
    return obj;
}

int	main(int argc, char **argv)
{
    MyString &&tmp = func();  //用一个右值引用来接收 g++ -fno-elide-constructors
    return 0;
}

