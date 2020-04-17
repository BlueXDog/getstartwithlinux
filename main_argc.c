#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i=0;
    char *env;
    printf("PATH : %s\n",getenv("PATH"));
    printf ("ssh_client : %s\n",getenv("SSH_CLIENT"));
    for (i=0;i<argc; i++)
        printf("%s\n",argv[i]);

    return 0;
}
