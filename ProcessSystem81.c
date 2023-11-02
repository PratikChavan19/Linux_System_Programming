// Client for named pipe

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    int fd = 0;
    char *path = "/tmp/mypipe";
    char Buffer[100];

    printf("Client is runnimg and reading data from named pipe...\n");
    fd = open(path, O_RDONLY);

    read(fd, Buffer, 10);

    printf("Data from pipe is : %s\n", Buffer);

    return 0;
}