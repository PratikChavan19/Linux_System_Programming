#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside child process - PID of parent process is %d\n", getppid());

    return 0;
}