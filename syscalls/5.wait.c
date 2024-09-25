#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main() 
{
    int pid, i = 0;
    printf("ready to fork\n");
    pid = fork();
    if (pid == -1) 
    {
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) 
    {
        printf("child starts\n");
        for (i = 0; i < 10; i++) 
        {
            printf("child ends\n");
        }
    } 
    else 
    {
        printf("parent process continues\n");
    }
    return 0;
}
