#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Incorrect number of arguments\n");
        return -1;
    }

    int fd = 0;

    fd = open(argv[1], O_RDWR);

    if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	else
	{
		printf("File is succesfully opened with FD %d \n", fd);
	}

    return 0;
}