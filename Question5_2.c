#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Employee
{
    int EID;
    char Ename[20];
    int Salary;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Employee eobj;
    char Fname[20];
    int fd = 0;

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);

    read(fd,&eobj,sizeof(eobj));

    printf("Employee ID : %d : \n",eobj.EID);
    printf("Name : %s : \n",eobj.Ename);
    printf("Salary : %d : \n",eobj.Salary);
    printf("Age : %d : \n",eobj.Age);

    close(fd);

    return 0;
}