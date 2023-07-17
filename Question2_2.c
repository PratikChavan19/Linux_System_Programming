#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char str[100] = {'\0'};
    int ret = 0;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Enter the string you want to write\n");
    scanf("%[^\n]s", str);

    ret = write(fd, str, strlen(str));
    printf("Number of bytes get written in file are %d\n", ret);

    return 0;
}