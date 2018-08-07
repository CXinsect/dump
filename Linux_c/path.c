#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#define BUFFER_SIZR 4
#define OVER -1
typedef struct producers{
    int buf[BUFFER_SIZR];
    pthread_mutex_t mutex;
    int readpos,writepos;
    pthread_cond_t full;
    pthread_cond_t empty;
}PRODUCER;
void init(PRODUCER *p)
{
    pthread_mutex_init(&p->mutex,NULL);
    pthread_cond_init(&p->empty,NULL);
    pthread_cond_init(&p->full,NULL);
    p->readpos = 0;
    p->writepos = 0;
}
void put(PRODUCER *p,int data)
{
    pthread_mutex_lock(&p->mutex);
    while((p->writepos+1) % BUFFER_SIZR == p->readpos)
    {
        pthread_cond_wait(&p->full,&p->mutex);
    }
    p->buf[p->writepos++] = data;
    if(p->writepos >= BUFFER_SIZR)
    p->writepos = 0;
    pthread_cond_signal(&p->empty);
    pthread_mutex_unlock(&p->mutex);
}
int  get(PRODUCER *p)
{
    int data;
    pthread_mutex_lock(&p->mutex);
    while(p->readpos == p->writepos)
    pthread_cond_wait(&p->empty,&p->mutex);
    data = p->buf[p->readpos++];
    if(p->readpos >= BUFFER_SIZR)
     p->readpos = 0;
     pthread_cond_signal(&p->full);
     pthread_mutex_unlock(&p->mutex);
     return data;
}
PRODUCER buffer;
void *producer(void * data)
{
    int n;
    for(n = 0;n<10;n++)
    {
        printf("生产者%d\n",n);
        put(&buffer,n);
    }
    put(&buffer,OVER);
    pthread_exit(NULL);
}
void* consumer(void * data)
{
    int d;
    while(1)
    {
        d = get(&buffer);
        if(d == OVER)
        break;
        printf("消费者%d\n",d);
    }
    pthread_exit(NULL);
}
int main (int argc,char * argv[])
{
    pthread_t thid1,thid2;
    void * ret;
    pthread_create(&thid1,NULL,(void*)&producer,NULL);
    pthread_create(&thid2,NULL,(void*)&consumer,NULL);
    pthread_join(thid1,&ret);
    pthread_join(thid2,&ret);
    return 0;
}