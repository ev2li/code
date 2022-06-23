#include <iostream>

using namespace std;

#if 0
//递归终止函数
void debug(){
    cout << "empty" << endl;
}
#endif

//递归终止函数
template<class T>
void debug(T tmp){
    cout << "tmp = " << tmp << endl;
}

//可变参数的模板函数
template<class T1, class ...T2>
void debug(T1 first, T2... last){
    cout  << "first:" << first << endl;
    //递归调用函数本身
    debug(last...);
}


int	main(int argc, char **argv)
{
    debug(1, 2, 3, 4);
    /*
        函数递归调用过程
        1.debug(1, 2, 3, 4);
        2.debug(2, 3, 4);
        3.debug(3, 4);
        4.debug(4);
        5.debug();
    */

    debug(1, "mike", 3.14, 'a');
    return 0;
}

