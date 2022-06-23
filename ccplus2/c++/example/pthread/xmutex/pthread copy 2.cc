#include<iostream>
#include<thread>
#include<string>

using namespace std;

class Para{
public:
    Para(){cout << "Create Para" << endl;}
    Para(const Para &p) {cout << "Copy Para" << endl;}
    ~Para(){cout << "Drop Para" << endl;}
public:
    string name;
};

void ThreadMain(int p1, float p2, string str, Para p4){
    this_thread::sleep_for(chrono::milliseconds(100));
    std::cout << "ThreadMain" << p1 << " " << p2 << " " << str <<" " << p4.name << std::endl;
}
void ThreadMainPtr(Para* p){
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "ThreadMainPtr name = " << p->name << endl;
}

void ThreadMainRef(Para& p){
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "ThreadMainPtr name = " << p.name << endl;
}

int main(){
    {
        Para p;
        p.name = "test ThreadMainPtr name";
        thread th(ThreadMainRef, std::ref(p));
        th.join();
    }
    getchar();
    {
        //传递线程指针
        Para p;
        p.name = "test ThreadMainPtr name";
        thread th(ThreadMainPtr, &p);
        th.join();
        getchar();
    }

    {
        //传递线程指针
        Para p;
        p.name = "test ThreadMainPtr name";
        thread th(ThreadMainPtr, &p);
        th.detach(); //这个会出现问题
    }
    //Para已释放
    getchar();
    thread th;
    {
        float f1 = 12.1f;
        Para p;
        p.name = "test Para class";
        th = thread(ThreadMain, 101, f1, "test string params", p);
    }
    th.join();
    return 0;
}