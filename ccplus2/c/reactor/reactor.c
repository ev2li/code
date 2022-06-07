#include <sys/epoll.h>

/**
 * 1.检测IO事件
 * 2.read/write
 * 3.解析
 * 检测IO是什么事件
 */
#define EVENT_LENGTH 1024

typedef int NCALLBACK(int fd, int events, void*arg);

//fd - item
struct item {
    int clienfd;
    unsigned char rbuffer[1024];
    int rlen;

    unsigned char wbuffer[4096];
    int wlen; //writeable length
    int wsize; //writed

#if 1
    NCALLBACK *readcb;
    NCALLBACK *writecb;
    NCALLBACK *acceptcb;
#else
    NCALLBACK *callback;
#endif
};

struct item_block{
    int use_count;
    struct item items[1024];
    struct item_block *next;
};

struct reactor {
    int epfd;
    struct item_block *block;
    int count;
    int ucount;
};

struct item *get_item_by_clientfd(int clientfd){
    //return
}

#if 0
struct reactor *reactor_init(int size){
    struct reactor *r = malloc(sizeof(struct reactor));
}

int reactor_deinit(struct reactor *r){
    free(r);
}
#else
int reactor_init(struct reactor *r){
    r->epfd = epoll_create(1);
    r->items = malloc(1024 * sizeof(struct item));
    r->count = 1024;
    r->ucount = 0;
}

int reactor_deinit(struct reactor *r){
    close(r->fd);
}
#endif
int init_server(){ //return listenfd

}

#if 1
int accpet_callback(int fd, int events, void*arg){

}

int recv_callback(int fd, int events, void*arg){

}

int send_callback(int fd, int events, void*arg){

}
#endif

int set_event(int fd, NCALLBACK cb){

}


int main(){
    int epfd = epoll_create(1);
    int sockfd = init_server();

    struct epoll_event ev = {0};
    ev.event = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);
    struct epoll_event events[EVENT_LENGTH] = {0};

    while(1){
        int nready = epoll_wait(epfd, events[EVENT_LENGTH], -1);
        int i = 0;
        for(i = 0; i < nready; i++){
            struct item *it = get_item_by_clientfd(events[i].data.fd);
            if(events[i].data.fd == sockfd){ //accept
#if 1
                it->acceptcb(events[i].data.fd, events.event, it);
#else
                struct sockaddr_in client;
                socketlen_t len = sizeof(client);
                int clientfd = accept(sockfd, (struct sockaddr*)&client, len);
                struct epoll_event ev = {0};
                ev.event = EPOLLIN;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clientfd, &ev);
#endif
            }else{
#if 0
                it->callback(events[i].data.fd, events[i].event, it);
#else
                if(events[i].event & EPOLLIN){ //readable
                    //it->rlen =  recv(events[i].data.fd, it->rbuffer + it->rlen, 1024 - it->rlen, 0);
                    it->readcb(it->clienfd, events[i].event, it);

                }

                if(events[i].event & EPOLLOUT){ //writeable
                    //int ret = send(events[i].data.fd, it->wbuffer + it->wsize, it->wlen - it->wsize, 0);
                    //it->wsize += ret;
                    it->writecb(it->clienfd, events[i].event, it);
                }
#endif
            }
        }
    }
}