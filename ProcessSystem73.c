#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThredProc1(void *ptr)
{
    char Buffer[512];
    int fd = 0, iCnt = 0, iRet = 0, i = 0;

    fd = open("Demo.txt", O_RDONLY);

    while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }
    
    printf("Number of capital characters are : %d\n", iCnt);
    close(fd);
    pthread_exit(NULL);
}

void * ThredProc2(void *ptr)
{
    char Buffer[512];
    int fd = 0, iCnt = 0, iRet = 0, i = 0;

    fd = open("Demo.txt", O_RDONLY);

    while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }
    
    printf("Number of small characters are : %d\n", iCnt);
    close(fd);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,          // Address of pthread_attr_t structure object
                         NULL,          // Thread attributes
                         ThredProc1,     // Address of callback function
                         NULL);          // Parameters to callback function
    
    if(ret1 != 0)
    {
        printf("Unable to create thread1\n");
        return -1;
    }
    printf("Thread1 is created with ID : %u\n", TID1);

    ret2 = pthread_create(&TID2,          // Address of pthread_attr_t structure object
                         NULL,          // Thread attributes
                         ThredProc2,     // Address of callback function
                         NULL);          // Parameters to callback function
    
    if(ret2 != 0)
    {
        printf("Unable to create thread2\n");
        return -1;
    }
    printf("Thread2 is created with ID : %u\n", TID2);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);
    
    
    printf("End of main thread\n");
    pthread_exit(NULL);
    return 0;
}