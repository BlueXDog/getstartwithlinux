#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid, status;
    if (argc!=2)
    {
        puts("incorrect pass argument ");
        return -1;
    }

    pid =fork();
    if (pid<0)
    {
        perror("fork error");
        return -2;
    }
    else if (pid==0)
    {
        if ( execl("./child","./child",argv[1],NULL)==-1){
            perror("execl error");
        }


    }
    else{
        wait(&status);
        printf("status :%s\n",(status==0)?"ok":"fail");

    }
    return 0;
}
