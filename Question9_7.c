#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

int main()
{
    char path[50];

    char *username = (char *)malloc(10*sizeof(char));
    username=getlogin();
    
    printf("%s\n", username);

    return 0;
}