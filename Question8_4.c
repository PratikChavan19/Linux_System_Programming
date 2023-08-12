#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret1 = 0, Ret2 = 0;
    int cpid1 = 0, cpid2 = 0;
    int Exit_status1 = 0, Exit_status2 = 0;

    Ret1 = fork();
    Ret2 = fork();

    if(Ret1 == 0)  
    {
        printf("Process1 created successfully with PID %d\n", getpid());
    }
    else
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid1 = wait(&Exit_status1);
        printf("Child process1 terminated having PID %d with exit status %d\n",cpid1,Exit_status2);
    }
    if(Ret2 == 0)  
    {
        printf("Process2 created successfully with PID %d\n", getpid());
    }
    else
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid2 = wait(&Exit_status2);
        printf("Child process2 terminated having PID %d with exit status %d\n",cpid2,Exit_status2);
    }

    return 0;
}
