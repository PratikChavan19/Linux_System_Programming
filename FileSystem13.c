#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	int Ret = 0;
	char *Buffer = NULL;
	int Size = 0;
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	Size = atoi(argv[2]);
	
	Buffer = (char *)malloc(Size);
	
	Ret = read(fd, Buffer, Size);
	if(Ret == 0)
	{
		printf("Unable to read data from file\n");
		return -1;
	}
	
	printf("Data from file is : \n");
	write(1, Buffer, Ret);

	return 0;
}
