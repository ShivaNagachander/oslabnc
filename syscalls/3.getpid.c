#include<stdio.h>
#include <unistd.h>
#include<sys/types.h>
int main()
{
printf("\n parent process id %d",getppid());
printf("\n child process id %d\n",getpid());
}


 parent process id 17861
 child process id 17868

