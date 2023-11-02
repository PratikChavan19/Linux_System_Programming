#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;

    Ret = fork();

    if(Ret == 0)
    {
        printf("Child process is running\n");
    }
    else
    {
        printf("Parent process is running\n");
    }

    return 0;
}