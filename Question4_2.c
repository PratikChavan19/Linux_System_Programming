#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int dp = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = mkdir(argv[1], S_IRWXU);
    if(dp == -1)
    {
        printf("Unable to create directory\n");
        return -1;
    }
    else if(dp == 0)
    {
        printf("Directory created successfully\n");
    }    

    return 0;
}