#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>

int fn(void *arg)
{
    printf("\ngia tri nhan duoc la :%d",atoi(arg));
    printf("\nInFO:this code is running under the child process\n ");
       return 0;
}

int  main(int argc, char *argv[])
{
    void *pchild_stack=malloc(1024*1024);
    int status;
    if (pchild_stack==NULL)
    {
        printf("ERROR: unable to alllocate memory \n");
        exit (EXIT_FAILURE);

    }

    int pid=clone(fn,pchild_stack+(1024*1024),SIGCHLD,argv[1]);
    if (pid<0)
    {
        printf("error: unable to create child process\n");
        exit(EXIT_FAILURE);
    }
    wait(&status);
    printf("status :%s\n",(status==0)?"ok ":"failed");
    free(pchild_stack);
    printf("info :child process terminated.\n");

    return 0;

}
