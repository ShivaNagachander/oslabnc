#include <stdio.h>
#include <unistd.h> 

int main()
{
    printf("Before FORK \n");
    fork();
    printf("After FORK \n\n");

    return 0;
}
Before FORK 
After FORK 

After FORK 
