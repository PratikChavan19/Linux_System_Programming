// Demonstration of Multiprocessing

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int ret1 = 0, ret2 = 0;
    int pid1, pid2;
    int status1, status2;

    ret1 = fork();
    if(ret1 == 0)
    {
        execl("./Process1", "NULL", NULL);
    }

    wait(&status1);

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./Process2", "NULL", NULL);
    }

    wait(&status2);
    
    return 0;
}