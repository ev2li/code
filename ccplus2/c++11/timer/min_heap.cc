#ifndef intIME_HEAP
#define intIME_HEAP

#include <iostream>
#include <netinet/in.h>
#include <time.h>
using std::exception;

#define BUFFER_SIZE 64

/**
 * @brief 
 * 时间轮定时器：是使用固定频率的调用心搏函数tick,并且在其中以此检测到期的定时器，然后执行到期定时器上的回调函数
 * 最小堆定时器：我们将所有定时器中超时时间最小的一个定时器的超时时间作为心搏间隔，这样，一旦心博函数tick被调用
 * 那么超时时间最小的一个定时器必然到期，然后再找出超时时间最小的那一个，并将这段时间设置为下一次心搏间隔 
 */

class heap_timer;
// 绑定socket和定时器
struct client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[ BUFFER_SIZE ];
    heap_timer* timer;
};

// 定时器类
class heap_timer
{
public:
    heap_timer( int delay )
    {
        expire = time( NULL ) + delay;
    }

public:
   time_t expire; // 定时器生效的绝对时间
   void (*cb_func)( client_data* ); // 定时器的回调函数
   client_data* user_data; // 用户数据
};
// 时间堆类
class time_heap
{
public:
    // 初始化一个空的堆，大小为cap
    time_heap( int cap ) throw ( std::exception )
        : capacity( cap ), cur_size( 0 )
    {
	array = new heap_timer* [capacity];
	if ( ! array )
	{
            throw std::exception();
	}
        for( int i = 0; i < capacity; ++i )
        {
            array[i] = NULL;
        }
    }
    // 使用已有的数组来初始化堆
    time_heap( heap_timer** init_array, int size, int capacity ) throw ( std::exception )
        : cur_size( size ), capacity( capacity )
    {
        if ( capacity < size )
        {
            throw std::exception();
        }
        array = new heap_timer* [capacity];
        if ( ! array )
        {
            throw std::exception();
        }
        for( int i = 0; i < capacity; ++i )
        {
            array[i] = NULL;
        }
        if ( size != 0 )
        {
            for ( int i =  0; i < size; ++i )
            {
                array[ i ] = init_array[ i ];
            }
            for ( int i = (cur_size-1)/2; i >=0; --i )
            {
                // 堆数组的父结点进行下操作
                percolate_down( i );
            }
        }
    }
    // 销毁时间堆
    ~time_heap()
    {
        for ( int i =  0; i < cur_size; ++i )
        {
            delete array[i];
        }
        delete [] array; 
    }

public:
    // 添加目标定时器timer
    void add_timer( heap_timer* timer ) throw ( std::exception )
    {
        if( !timer )
        {
            return;
        }
        if( cur_size >= capacity ) // 如果当前堆数组的空间不够，那么将其扩大一倍
        {
            resize();
        }
        // hole是新建位置，新插入了一个元素，cur_size++
        int hole = cur_size++;
        int parent = 0;
        for( ; hole > 0; hole=parent )
        {
            parent = (hole-1)/2;
            if ( array[parent]->expire <= timer->expire )
            {
                break;
            }
            array[hole] = array[parent];
        }
        array[hole] = timer;
    }
    // 这里的删除为假删除删除
    void del_timer( heap_timer* timer )
    {
        if( !timer )
        {
            return;
        }
        // lazy delelte
        timer->cb_func = NULL;
    }
    // 获得堆顶部
    heap_timer* top() const
    {
        if ( empty() )
        {
            return NULL;
        }
        return array[0];
    }
    // 删除顶部
    void pop_timer()
    {
        if( empty() )
        {
            return;
        }
        if( array[0] )
        {
            delete array[0];
            array[0] = array[--cur_size];
            percolate_down( 0 );
        }
    }
    // 心搏函数
    void tick()
    {
        heap_timer* tmp = array[0];
        time_t cur = time( NULL );
        while( !empty() )
        {
            if( !tmp )
            {
                break;
            } // 如果堆顶定时器没有到期，那么退出循环
            if( tmp->expire > cur )
            {
                break;
            } // 否则执行堆顶定时器中的任务
            if( array[0]->cb_func )
            {
                array[0]->cb_func( array[0]->user_data );
            } // 将堆顶元素删除，同时生成新的堆顶定时器(array[0])
            pop_timer();
            tmp = array[0];
        }
    }
    bool empty() const { return cur_size == 0; }

private:
    // 最小堆的下滤操作
    void percolate_down( int hole )
    {
        heap_timer* temp = array[hole];
        int child = 0;
        for ( ; ((hole*2+1) <= (cur_size-1)); hole=child )
        {
            child = hole*2+1;
            if ( (child < (cur_size-1)) && (array[child+1]->expire < array[child]->expire ) )
            {
                ++child;
            }
            if ( array[child]->expire < temp->expire )
            {
                array[hole] = array[child];
            }
            else
            {
                break;
            }
        }
        array[hole] = temp;
    }
    // 将堆数组的容量扩大一倍
    void resize() throw ( std::exception )
    {
        heap_timer** temp = new heap_timer* [2*capacity];
        for( int i = 0; i < 2*capacity; ++i )
        {
            temp[i] = NULL;
        }
        if ( ! temp )
        {
            throw std::exception();
        }
        capacity = 2*capacity;
        for ( int i = 0; i < cur_size; ++i )
        {
            temp[i] = array[i];
        }
        delete [] array;
        array = temp;
    }

private:
    heap_timer** array; // 堆数组
    int capacity; // 堆数组的容量
    int cur_size; // 堆数组当前包含的元素个数
};

#endif