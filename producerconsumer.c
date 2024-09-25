#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 10
int mutex = 1;
int empty = BUFFERSIZE;
int full = 0;
int buffer[BUFFERSIZE];
int in = 0, out = 0;
int n;
void wait(int *s) {
    while (*s <= 0);
    (*s)--;
}
void signal(int *s) {
    (*s)++;
}
void producer() {
    int item;
    if (in < n) {
        wait(&empty);
        wait(&mutex);
        printf("\nEnter an item: ");
        scanf("%d", &item);
        buffer[in] = item;
        printf("Produced item: %d at position %d\n", item, in);
        in = (in + 1) % BUFFERSIZE;
        signal(&mutex);
        signal(&full);
    }
}
void consumer() {
    if (out < in) {
        wait(&full);
        wait(&mutex);
        int item1 = buffer[out];
        printf("Consumed item: %d from position %d\n", item1, out);
        out = (out + 1) % BUFFERSIZE;
        signal(&mutex);
        signal(&empty);
    }
}
int main() {
    printf("Enter the number of items to produce and consume: ");
    scanf("%d", &n);
    while (in < n) {
        producer();
    }
    while (out < in) {
        consumer();
    }
    return 0;
}

O/P:
Enter the number of items to produce and consume: 3

Enter an item: 2
Produced item: 2 at position 0

Enter an item: 4
Produced item: 4 at position 1

Enter an item: 8
Produced item: 8 at position 2
Consumed item: 2 from position 0
Consumed item: 4 from position 1
Consumed item: 8 from position 2
