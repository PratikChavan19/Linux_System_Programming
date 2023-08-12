#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

void fun()
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    char path[50];

    char *username = (char *)malloc(10*sizeof(char));
    username=getlogin();
    
    sprintf(path,"/home/%s/Desktop",username);

    dp = opendir(path);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    } 

    fd = creat("Demo.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        write(fd,entry->d_name,20);
    }
    close(dp);
}

int main()
{
    int Ret = 0;
    int cpid = 0;
    int ExitStatus = 0;

    Ret = fork();

    if(Ret == 0)
    {
        fun();
    }
    else
    {
        cpid = wait(&ExitStatus);
    }

    return 0;
}