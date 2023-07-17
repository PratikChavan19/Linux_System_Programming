#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("Entries from the directory file are : \n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%s\n",entry->d_name);
    }

    closedir(dp);
    return 0;
}