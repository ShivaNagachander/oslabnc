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




O/P:
Ready to fork
Child process starts
Child process running 0
Child process running 1
Child process running 2
Child process running 3
Child process running 4
Child process running 5
Child process running 6
Child process running 7
Child process running 8
Child process running 9
Child process ends
Parent process running 0
Parent process running 1
Parent process running 2
Parent process running 3
Parent process running 4
Parent process running 5
Parent process running 6
Parent process running 7
Parent process running 8
Parent process running 9
Parent process ends
