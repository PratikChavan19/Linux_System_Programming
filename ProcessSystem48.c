#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void fun()
{
        printf("Running process PID is : %d\n",getpid());
}

int main()
{
    int Ret = 0;

    Ret = fork();

    if(Ret == 0)
    {
        fun();
    }
    else
    {
        fun();
    }

    return 0;
}