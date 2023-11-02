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
        printf("Child says : PID of parent process is : %d\n", getppid());
        printf("Child says : PID of child process is : %d\n", getpid());
        
    }
    else
    {
        printf("Parent process is running\n");
        printf("Parent says : PID of child process is : %d\n", Ret);
        printf("Parent says : PID of parent process is : %d\n", getpid());
        printf("Parent says : PID of parent process of paremt ie Terminal is : %d\n", getppid());
    }

    return 0;
}