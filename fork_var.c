#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int var_glo;


int main()
{
    int var_loc;
    int pid;
    pid=fork();
    if (pid >=0){
        printf("make child process succes\n");
        if (pid ==0)
        {
            var_glo++;
            var_loc++;
            printf("gia tri var trong process con global=%d local=%d\n",var_glo,var_loc);
            printf("var address in child global=%x local=%x\n",&var_glo,&var_loc);

        }
        else{
            var_glo=10;
            var_loc=20;
            printf("gia tri trong process cha global=%d local=%d\n",var_glo,var_loc);

            printf("var address in cha process : global=%x local=%x\n",&var_glo,&var_loc);
            printf("pid cua process cha %d ",pid );
            while(1);
        }
    }
    else{
        printf("fork failed\n ");
        return 1;

    }
    return 0;
}
