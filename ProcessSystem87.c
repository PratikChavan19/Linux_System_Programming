// Client for shared memory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int Key = 1234;
    char *ptr = NULL;

    printf("Client application running\n");    

    shmid = shmget(Key, shmsize, 0666);

    ptr = shmat(shmid, NULL, 0);

    if(ptr != NULL)
    {
        printf("Shared memory attatched successfully...\n");
    }

    printf("Data from shared memory is : \n");
    while(*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }

    shmdt(shmid);

    return 0;
}