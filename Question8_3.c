#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret1 = 0, Ret2 = 0, Ret3 = 0;

    Ret1 = fork();
    Ret2 = fork();
    Ret3 = fork();

    if(Ret1 == 0)  
    {
        printf("Process1 created successfully with PID %d\n", getpid());
    }
    if(Ret2 == 0)  
    {
        printf("Process2 created successfully with PID %d\n", getpid());
    }
    if(Ret3 == 0)  
    {
        printf("Process3 created successfully with PID %d\n", getpid());
    }
    else
    {
        printf("Parent is running with PID : %d\n",getpid());
    }

    return 0;
}
