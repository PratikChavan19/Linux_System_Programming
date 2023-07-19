#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    int fd = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE];
    int iCnt = 1;

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("File Number : %d\n", iCnt);
            printf("File name : %s\n",entry->d_name);
            printf("File size is : %d\n",sobj.st_size);
            printf("Number of links : %d\n",sobj.st_nlink);
            printf("Inode number : %d\n",sobj.st_ino);
            printf("File system number : %d\n",sobj.st_dev);
            printf("Number of blocks : %d\n",sobj.st_blocks);

            fd = open(name, O_RDONLY);
            if(fd == -1)
            {
                printf("Unable to open file\n");
                return -1;
            }

            printf("Data from file : \n");
            while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
            {
                write(1,Buffer,Ret);
            }
            
            close(fd);
            iCnt++;
        }
        printf("\n----------------------------------------------------------------------\n");
    }

    closedir(dp);
    
    return 0;
}