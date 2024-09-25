#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
int main() 
{
    int p = fork();
    if (p == 0) 
    {
        printf("\nChild created\n");
        exit(0); 
    }
    if (p < 0) 
    {
        printf("Can't create child\n");
        exit(-1); 
    }
    printf("Process ended\n");
    return 0; 
}
