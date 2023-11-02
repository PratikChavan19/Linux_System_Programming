#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThredProc(void *ptr)
{
    printf("Value received from main thread is : %d\n", (int)ptr);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 11;

    ret = pthread_create(&TID,          // Address of pthread_attr_t structure object
                         NULL,          // Thread attributes
                         ThredProc,     // Address of callback function
                         (int *)no);          // Parameters to callback function
    
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %u\n", TID);
    pthread_join(TID, NULL);  
    printf("End of main thread\n");
    return 0;
}