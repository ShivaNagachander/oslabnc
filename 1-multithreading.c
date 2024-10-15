#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void* print_even(void* arg) 
{
    int i;
    for (i = 0; i <= 10; i += 2) 
    {
        printf("Even: %d\n", i);
        sleep(1);
    }
    return NULL;
}
void* print_odd(void* arg) 
{
    int i;
    for (i = 1; i <= 10; i += 2) 
    {
        printf("Odd: %d\n", i);
        sleep(1);
    }
    return NULL;
}
int main() 
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, print_even, NULL);
    pthread_create(&thread2, NULL, print_odd, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Threads completed execution.\n");
    return 0;
}
Odd: 1
Even: 0
Odd: 3
Even: 2
Odd: 5
Even: 4
Odd: 7
Even: 6
Odd: 9
Even: 8
Even: 10
Threads completed execution.
