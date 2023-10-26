#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[1])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fd = creat(argv[1], 0777);
    if(fd != -1)
    {
        printf("File is succesfully created with FD %d \n", fd);
    }

    return 0;
}