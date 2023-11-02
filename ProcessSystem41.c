#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int PID = 0;

    PID = getpid();

    printf("PID of running process is : %d\n", PID);

    return 0;
}