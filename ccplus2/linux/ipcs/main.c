#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "debug.h"

#define MAXLINE 256

int main(void){
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0){
        ERROR_EXIT("pipe error")
    }

    if ((pid = fork()) < 0){
        ERROR_EXIT("fork error");
    }else if (pid > 0){ //parent
        close(fd[0]);
        write(fd[1], "hello pipe\n", 12);
    }else{ //child
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDIN_FILENO, line, n);
    }
    return 0;
}