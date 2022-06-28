#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    @brief  一元谓词(pred)返回值是bool类型的仿函数 
*/

class GreaterFive{
public:
        bool operator()(int val){
                return val > 5;
        }
};
void test01(){
        std::vector<int> v;
        for (size_t i = 0; i < 10; i++) {
                v.push_back(i);
        }

        //查找容器中，有没有大于5的数字 GreaterFive匿名函数对象
        // std::vector<int>::iterator it = find_if(v.begin(), v.end( ),  GreaterFive());
        auto it = find_if(v.begin(), v.end( ),  GreaterFive());

        if(it == v.end()){
                std::cout << "未找到" << std::endl;
        }else{
                std::cout << "找到了大于5的数字为:" << *it << std::endl;
        }
}

int main(){
        test01();
        return 0;
}