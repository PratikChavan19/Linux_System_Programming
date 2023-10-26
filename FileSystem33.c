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

    fd = open(argv[1], O_RDWR);
    if(fd != -1)
    {
        printf("File is existing\n");
    }
    else
    {
        fd = creat(argv[1], 0777);
        if(fd != -1)
        {
            printf("New file gets created\n");
        }
    }

    return 0;
}