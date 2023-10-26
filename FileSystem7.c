#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	else
	{
		printf("File is succesfully opened with fd %d \n", fd);
	}
	
	return 0;	
}
