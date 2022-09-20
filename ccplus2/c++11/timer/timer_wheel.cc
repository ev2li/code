#ifndef TIME_WHEEL_TIMER
#define TIME_WHEEL_TIMER

#include <time.h>
#include <netinet/in.h>
#include <stdio.h>

#define BUFFER_SIZE 64


/**
 * @brief 时间轮是一个轮，轮子上有很多的槽，每个槽里面包含很多定时器，整个轮子以恒定的速度转动，每转一下指向下一个槽
 * 槽和槽之之间的时间间隔为si(我们称其为心搏时间), 一个轮子有N个槽，所以转动一周的时间是N*si
 * 假设当前指针指向的槽称之为CS，现在要添加一个定时时间为ti的定时器，那么该定时器将被插入槽ts为:
 * ts = (cs + (ti/si)) % N; 
 */
class tw_timer;
// 绑定socket和定时器
struct client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[ BUFFER_SIZE ];
    tw_timer* timer;
};

// 定时器类
class tw_timer
{
public:
    tw_timer( int rot, int ts ) 
    : next( NULL ), prev( NULL ), rotation( rot ), time_slot( ts ){}

public:
    int rotation; // 记录定时器在时间轮旋转多少圈后生效
    int time_slot; // 记录定时器属于时间轮上的哪个槽
    void (*cb_func)( client_data* ); // 定时器的回调函数
    client_data* user_data; // 客户数据
    tw_timer* next; // 指向下一个定时器
    tw_timer* prev; // 指向前一个定时器
};

//时间轮类
class time_wheel
{
public:
    time_wheel() : cur_slot( 0 )
    {
        for( int i = 0; i < N; ++i )
        {
            slots[i] = NULL; // 初始化每个槽的头节点
        }
    }
    ~time_wheel()
    {
        for( int i = 0; i < N; ++i ) // 析构方法遍历每个槽，然后销毁其中的定时器
        {
            tw_timer* tmp = slots[i];
            while( tmp )
            {
                slots[i] = tmp->next;
                delete tmp;
                tmp = slots[i];
            }
        }
    }
    // 根据定时的值timeout创建一个定时器，然后将其放入合适的槽当中。
    tw_timer* add_timer( int timeout )
    {
        if( timeout < 0 )
        {
            return NULL;
        }
        int ticks = 0;
        // 计算转动多少下才被触发
        if( timeout < TI )
        {
            ticks = 1;
        }
        else
        {
            ticks = timeout / TI;
        }
        // 计算转动多少圈才被触发
        int rotation = ticks / N;
        // 定时器具体在哪个槽当中
        int ts = ( cur_slot + ( ticks % N ) ) % N;
        // 创建新的定时器，位于第ts个槽上
        tw_timer* timer = new tw_timer( rotation, ts );
        // 将定时器插入
        if( !slots[ts] )
        {
            printf( "add timer, rotation is %d, ts is %d, cur_slot is %d\n", rotation, ts, cur_slot );
            slots[ts] = timer;
        }
        else
        {
            timer->next = slots[ts];
            slots[ts]->prev = timer;
            slots[ts] = timer;
        }
        return timer;
    }
    // 删除定时器
    void del_timer( tw_timer* timer )
    {
        if( !timer )
        {
            return;
        }
        int ts = timer->time_slot;
        // slots[ts]是目标定时器的头节点，如果目标定时器就是该头节点，那么需要重置第ts个槽的头节点
        if( timer == slots[ts] )
        {
            slots[ts] = slots[ts]->next;
            if( slots[ts] )
            {
                slots[ts]->prev = NULL;
            }
            delete timer;
        }
        else
        {
            timer->prev->next = timer->next;
            if( timer->next )
            {
                timer->next->prev = timer->prev;
            }
            delete timer;
        }
    }
    // SI时间到后，调用该函数，时间轮向前滚动一个槽
    void tick()
    {
        tw_timer* tmp = slots[cur_slot]; // 获得当前槽的头节点
        printf( "current slot is %d\n", cur_slot );
        while( tmp )
        {
            printf( "tick the timer once\n" );
            // 如果定时器的rotation值大于0，那么在这一轮不起作用
            if( tmp->rotation > 0 )
            {
                tmp->rotation--;
                tmp = tmp->next;
            }
            // 否则时辰已到，执行任务，并且销毁该定时器
            else
            {
                tmp->cb_func( tmp->user_data );
                // 如果是头节点
                if( tmp == slots[cur_slot] )
                {
                    printf( "delete header in cur_slot\n" );
                    slots[cur_slot] = tmp->next;
                    delete tmp;
                    if( slots[cur_slot] )
                    {
                        slots[cur_slot]->prev = NULL;
                    }
                    tmp = slots[cur_slot];
                }
                else
                {
                    tmp->prev->next = tmp->next;
                    if( tmp->next )
                    {
                        tmp->next->prev = tmp->prev;
                    }
                    tw_timer* tmp2 = tmp->next;
                    delete tmp;
                    tmp = tmp2;
                }
            }
        }
        cur_slot = ++cur_slot % N; // 别忘了更新时间轮的当前槽，反映时间轮的转动。
    }

private:
    static const int N = 60; // 时间轮上的槽的数量
    static const int TI = 1;  // 每秒转动一次，间隔为1
    tw_timer* slots[N]; // 时间轮的槽，每个槽指向一个定时器链表，注意，链表是无序的！
    int cur_slot; // 当前所处的槽
};

#endif

/**
 * 每添加一个定时器的时间复杂度为O(1),删除一个定时器的时间复杂度是O(1),执行一个定时器任务的时间复杂度为O(n)
 * 实际上，当槽越多的时候，执行一个定时器任务的时间复杂度为O(n)
 */
