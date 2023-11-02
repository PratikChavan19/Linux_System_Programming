#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

// void * _____(void *____)
// {}

void * ThredProc(void *ptr)
{
    printf("Inside thread\n");
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID,          // Address of pthread_attr_t structure object
                         NULL,          // Thread attributes
                         ThredProc,     // Address of callback function
                         NULL);          // Parameters to callback function
    
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %u\n", TID);

    return 0;
}