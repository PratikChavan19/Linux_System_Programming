#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    fork();

    printf("Hello World : %d\n", getpid());

    return 0;
}