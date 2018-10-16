#include "apue.h"

char buf[] "a write to stdout";
int glob =6;

int main() {

    int var;   
    pid_t pid;

    var = 88;
    if(pid = fork()  < 0) {

    }
    else if (pid == 0 ){
        glob++;
        var ++;
    }
    else {
        sleep(2);
    }
    printf("pid = %d , var = %d, glob = %d\n",getpid(), var, glob);
    return 0;
}