#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void handler_chld(int sig)
{
    printf("received sigchild from child process\n");
    wait(NULL);

}
int main(){
    int pid ;
    signal(SIGCHLD,handler_chld);

    pid =fork();
    if (pid <0){
        perror(" fork error\n");
        return -1 ;
    }
    else if (pid ==0)
    {
        //this is child process

        printf("this is child process\n");

        return 1;

    }
    else {
        //this is parent process

        printf("parent: %d\n",(int) getpid());

        printf("this is parent process\n ");
        while(1);

    }
}
