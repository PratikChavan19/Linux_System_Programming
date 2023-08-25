#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    int i1 = 1;

    while(i1 <= 500)
    {
        printf("%d\n", i1);
        i1++;
    }

    pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
    int i2 = 500;

    while(i2 >= 1)
    {
        printf("%d\n", i2);
        i2--;
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,        
                          NULL,       
                          ThreadProc1, 
                          NULL);      

    if(ret1 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread1 is created with ID : %d\n",TID1);

    ret2 = pthread_create(&TID2,        
                          NULL,       
                          ThreadProc2, 
                          NULL);     

    if(ret2 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread2 is created with ID : %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);


    printf("End of main thread\n");
    
    pthread_exit(NULL);
    return 0;
}