#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int p = fork(); 
    if (p == 0) {
        printf("\nChild process created\n");
        exit(0);
    } else if (p < 0) {
        printf("Failed to create child process\n");
        exit(-1); 
    }
    return 0;
}
