#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Incorrect number of arguments\n");
        return -1;
    }

    int fd = 0;
    int mode = 0;

    if(strcasecmp(argv[2], "Read") == 0)
	{
		mode = O_RDONLY;
	}
	else if(strcasecmp(argv[2], "Write") == 0)
	{
		mode = O_WRONLY;
	}
	else
	{
		mode = O_RDONLY;
	}

    fd = open(argv[1], mode);

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