#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

int main(int argc, char *argv[1])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char oldname[50];
    char newname[50];

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname, "%s/%s", argv[1], entry->d_name);
        sprintf(newname, "%s/%s", argv[2], entry->d_name);

        rename(oldname, newname);
    }

    closedir(dp);
    return 0;
}