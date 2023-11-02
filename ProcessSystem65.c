#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char Buffer[512];
    int fd = 0, iCnt = 0, iRet = 0, i = 0;

    fd = open("Demo.txt", O_RDONLY);

    while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }
    
    printf("Number of capital characters are : %d\n", iCnt);

    close(fd);
    return 0;
}