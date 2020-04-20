#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t write_mutex;

void *hello_thread(void *arg)
{
    FILE *fp;
    char* fileName=(char*)arg;
    printf("file name  %s\n ",fileName);
    char *data=" i love you more than you think 123456789123456789 ";
   // pthread_mutex_lock(&write_mutex);
    if ((fp=fopen(fileName,"a+"))==NULL)
    {
        return (void*)NULL;
    }
    else {
        //ghi gia tri vao file
        printf("open file success\n");
        int nsi =strlen(data);
        while (nsi--)
        {
            fputc(*data,fp);
            data++;
        }
        printf ("write file complete\n");
    }
    fclose(fp);
    //pthread_mutex_unlock(&write_mutex);



    return (void*)NULL;
}

void  main()
{

    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&write_mutex,NULL);
    pthread_create(&thread1,NULL,hello_thread,"vinhdatabase");
    pthread_create(&thread2,NULL,hello_thread,"vinhdatabase");
    int i=0;
    for (i=0;i<1000;i++)
    {
        sleep(1);
        printf ("in gia tri thu %d\n",i);
    }
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_mutex_destroy(&write_mutex);

}

