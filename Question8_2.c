#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret1 = 0, Ret2 = 0;
    int cpid1 = 0, cpid2 = 0;
    int Exit_status1 = 0, Exit_status2 = 0;

    Ret1 = fork();

    if(Ret1 == 0)  
    {
        printf("Child1 process is running\n");

        Ret2 = fork();

        if(Ret2 == 0)
        {
            printf("Child2 process is running\n");
        }
        else        
        {
            printf("Child1 is running with PID : %d\n",getpid());
            cpid2 = wait(&Exit_status1);
            printf("PID of child2 is : %d\n", cpid2);
        }

    }
    else        
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid1 = wait(&Exit_status1);
        printf("PID of child1 is : %d\n", cpid1);
    }

    return 0;
}
