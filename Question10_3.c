#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
  printf("Value received from main thread is : %d\n",(int)ptr);
  pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 11;

    ret = pthread_create(&TID,            
                          NULL,           
                          ThreadProc,     
                          (int *)no);    

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID);
    pthread_join(TID,NULL);
    printf("End of main thread\n");
    return 0;
}