#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	
	printf("Usage : Name_Of_Executable Name_Of_File \n");
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	fd = creat(argv[1], 777);
	if(fd == -1)
	{
		printf("Unable to create file\n");
		return -1;
	}
	else
	{
		printf("File is succesfully created with fd %d \n", fd);
	}
	
	return 0;	
}
