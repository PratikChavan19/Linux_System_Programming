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
    char type[18];

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
            strcpy(type,"Regular");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            strcpy(type,"Directory");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            strcpy(type,"Symblic_link");
        }
        printf("File name : %s File Type : %s\n",name,type);
    }

    closedir(dp);
    
    return 0;
}