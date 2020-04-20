#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int fn()
{
    printf("\n this is child process ");
    return 0;

}
int global;
int main()
{
    int pid;
    int local;
    pid=vfork();
    if (pid<0)
    {
        printf("\nError:make child process error");

        return 0;
    }
    else {
        if (pid==0){
            printf("\nrunning child process");
            global=10;
            local=10;
            printf("\ngia tri bien global=%d local=%d",global, local);
            fn();
        }
        else{
            printf("\nrunning parent process ");
            local++;
            global++;
            printf("\ngia tri bien global=%d local=%d ",global,local);

        }

    }
    return 1;
}
