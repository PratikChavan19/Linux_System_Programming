#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

void fun1()
{
    char Buffer1[512];
    int iCnt1 = 0, iRet1 = 0, i1 = 0, fd1 = 0;

    fd1 = open("Demo.txt",O_RDONLY);

    while((iRet1 = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        for(i1 = 0; i1 < iRet1 ; i1++)
        {
            if((Buffer1[i1] >= 'A') && (Buffer1[i1] <= 'Z'))
            {
                iCnt1++;
            }
        }
    }

    int fd3 = open("Count.txt",O_RDWR);

    write(fd3, &iCnt1, sizeof(iCnt1));

    close(fd1);
}

void fun2()
{
    char Buffer2[512];
    int iCnt2 = 0, iRet2 = 0, i2 = 0, fd2 = 0;

    fd2 = open("Hello.txt",O_RDONLY);

    while((iRet2 = read(fd2,Buffer2,sizeof(Buffer2))) != 0)
    {
        for(i2 = 0; i2 < iRet2 ; i2++)
        {
            if((Buffer2[i2] >= 'A') && (Buffer2[i2] <= 'Z'))
            {
                iCnt2++;
            }
        }
    }   

    int fd3 = open("Count.txt",O_RDWR);
    
    write(fd3, &iCnt2, sizeof(iCnt2));

    close(fd2);
}

int main()
{
    int Ret1 = 0, Ret2 = 0;
    int cpid1 = 0, cpid2 = 0;
    int ExitStatus1 = 0, ExitStatus2 = 0;    

    Ret1 = fork();

    if(Ret1 == 0)
    {
        fun1();
    }
    else
    {
        cpid1 = wait(&ExitStatus1);
    }

    Ret2 = fork();

    if(Ret2 == 0)
    {
        fun1();
    }
    else
    {
        cpid2 = wait(&ExitStatus2);
    }

    return 0;
}