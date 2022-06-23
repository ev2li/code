#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
/**
 * @brief 
 * RAII(Resource Acquisition Is Initialization)
 * 使用局部对象来管理资源的技术,称为资源获取即初始化,它的生命同期是由操作系统
 * 来管理的,无需人工介入,资源的销毁容易忘记,造成死锁或内存泄漏
 */

class Xmutex{
public:
    Xmutex(mutex &mux):mux_(mux){
        cout << "Lock" << endl;
        mux.lock();
    }

    ~Xmutex(){
        cout << "unLock" << endl;
        mux_.unlock();
    }

private:
    mutex& mux_;
};

static mutex mux;
void TestMutex(){
    Xmutex lock(mux);

}

int main(){
    getchar();
    return 0;
}

