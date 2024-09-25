#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int pid, i = 0;
    printf("Ready to fork\n");
    pid = fork(); 
    if (pid == 0) {
        printf("Child process starts\n");
        for (i = 0; i < 10; i++) {
            printf("Child process running %d\n", i);
            sleep(1);
        }
        printf("Child process ends\n");
    } else {
        wait(NULL); 
        for (i = 0; i < 10; i++) {
            printf("Parent process running %d\n", i);
            sleep(1);
        }
        printf("Parent process ends\n");
    }
    return 0;
}
