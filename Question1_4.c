#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Incorrect number of arguments\n");
        return -1;
    }

    struct stat sobj;

    stat(argv[1], &sobj);

    printf("FIle name : %s\n", argv[1]);
	printf("FIle size is : %d\n", sobj.st_size);
	printf("Number of links : %d\n", sobj.st_nlink);
	printf("Inode number : %d\n", sobj.st_ino);
	printf("File system number : %d\n", sobj.st_dev);
	printf("Number of blocks : %d\n", sobj.st_blocks);

    return 0;
}