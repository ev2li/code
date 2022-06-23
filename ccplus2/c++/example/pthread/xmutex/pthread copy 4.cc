#include<iostream>
#include<thread>
#include<string>

using namespace std;


class XThread{
public:
    virtual void Start(){
        is_exit_ = false;
        th_ = std::thread(&XThread::Main, this);
    }

    virtual void Stop(){
        is_exit_ = true;
        Wait();
    }

    virtual void Wait(){
        if(th_.joinable()){
            th_.join();
        }
    }

    bool is_exit(){
        return is_exit_;
    }

private:
    virtual void Main() = 0;
    std::thread th_;
    bool is_exit_ = false;
};

class TestXThread:public XThread{
public:
    void Main() override{ //线程入口函数
        cout << "TestXThread Main begin " << endl;
        while(!is_exit()){
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "." << flush;
        }
        cout << "TestXThread Main end " << endl;
    }
public:
    string name;
};

int main(){
    TestXThread testth;
    testth.Start();
    this_thread::sleep_for(chrono::seconds(3));
    testth.Stop();
    testth.Wait();
    return 0;
}