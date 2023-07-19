#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    int fd1 = 0, fd2 = 0;
    int Ret = 0;
    char Buffer[10] = {'\0'};

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd1 = creat("Demo.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {  
            fd2 = open(name, O_RDONLY);
            if(fd2 == -1)
            {
                printf("Unable to open file\n");
                return -1;
            }

            Ret = read(fd2,Buffer,10);

            write(fd1,Buffer,Ret);
            memset(Buffer, 0, sizeof(Buffer));
            
            close(fd2);
        }
    }

    closedir(dp);
    close(fd1);
    
    return 0;
}