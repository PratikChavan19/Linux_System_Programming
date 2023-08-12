#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/resource.h>

extern char **environ;

int main()
{
    char **env = environ;

    printf("Environment of running process is : \n");
    
    for(;*env != NULL; env++)
    {
        printf("%s : \n",*env);
    }
    
    return 0;
}
