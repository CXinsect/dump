/*创建四个子进程，每个子进程创建两个线程*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<wait.h>
#include<stdlib.h>
pthread_mutex_t mutex;
void*thread1(void * arg)
{
    pthread_mutex_lock(&mutex);
    printf("hello deepin\n");
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
void * thread2(void * arg)
{
    pthread_mutex_lock(&mutex);
        printf("hello world\n");
        pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
int main (int argc,char * argv[])
{
    pid_t pid;
    pthread_t thid1,thid2;
    void * ret;
    int status;
    int i = 0;
    for(i = 0;i< 2;i++)
    {
        if((pid = fork()) ==0)
        {
            if(pthread_create(&thid1,NULL,thread1,NULL) != 0)
            {
                printf("创建线程1失败\n");
                exit(1);
            }
            if(pthread_create(&thid2,NULL,thread2,NULL) != 0)
            {
                printf("创建线程2失败\n");
                exit(1);
            }
            pthread_exit(NULL);
            //pthread_exit(NULL);
        }
         else if (pid < 0)
         exit(1);
         else
         {
               sleep(2);
               printf("这是父进程\n");
                if(pthread_create(&thid1,NULL,thread1,NULL) != 0)
                {
                     printf("创建线程1失败\n");
                    exit(1);
                }
            if(pthread_create(&thid2,NULL,thread2,NULL) != 0)
            {
                printf("创建线程2失败\n");
                exit(1);
            }
         }
         waitpid(pid,&status,0);
    }
    return 0;
}
