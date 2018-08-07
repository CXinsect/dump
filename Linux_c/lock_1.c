#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#define false 0
#define true 1
void readfo();
void writefo();
char buffer[256];
int buf_flag = 0;
int retflag = false;
pthread_mutex_t mutex;
void readfo();
void write();
int main (int argc,char * argv[])
{
    pthread_t thid;
    void *ret;
    pthread_create(&thid,NULL,(void*)&readfo,NULL);
    writefo();
    pthread_exit(NULL);
    return 0;
}
void readfo()
{
    while(1)
    {
        if(retflag){
            return;
        }
        pthread_mutex_lock(&mutex);
        if(buf_flag == 1)
        {
            printf("%s\n",buffer);
            buf_flag = 0;
        }
        pthread_mutex_unlock(&mutex);
    }
}
void writefo()
{
    int i = 0;
    while(1)
    {
        if(i == 10){
         retflag = true;
         return;
        }
        pthread_mutex_lock(&mutex);
        if(buf_flag == 0)
        {
            sprintf(buffer,"this is %d",i++);
            buf_flag = 1;
        }
        pthread_mutex_unlock(&mutex);

    }
}
