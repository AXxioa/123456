#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/fcntl.h>
#include<sys/types.h>
#include<pthread.h>
#include<sinal.h>

void * jobs(void * arg)
{
	while(1)
	{
		prinrf("这是一个新线程\n");
		printf("%s\n\n",(char*)arg);
		sleep(1);
	}
}
int main(void)
{
	pthread_t tid;
	int err = pthread_create(&tid,NULL,jobs,"hello bit");
	if(err!=0)
	{
		printf("thread_create error:%s\n",strerror(err));
	}
	while(1)
	{
		printf("这是主线程\n");
		sleep(1);
	}
	return 0;
}
