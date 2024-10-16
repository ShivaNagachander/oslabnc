#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 10  // Size of the shared buffer

int mutex = 1;   // Mutual exclusion lock to ensure only one thread accesses the buffer at a time
int empty = BUFFERSIZE;  // Tracks the number of empty slots in the buffer
int full = 0;    // Tracks the number of filled slots in the buffer

int buffer[BUFFERSIZE];  // The shared buffer between producer and consumer
int in = 0, out = 0;  // Indices for producer and consumer
int n;  // Number of items to produce and consume

// Function to simulate 'wait' (decrement semaphore)
void wait(int *s) {
    while (*s <= 0);  // Busy wait until the resource becomes available
    (*s)--;  // Decrement semaphore
}

// Function to simulate 'signal' (increment semaphore)
void signal(int *s) {
    (*s)++;  // Increment semaphore
}

// Producer function: Adds items to the buffer
void producer() {
    int item;
    if (in < n) {  // Check if more items need to be produced
        wait(&empty);  // Wait until an empty slot is available
        wait(&mutex);  // Lock the buffer (mutex) to ensure exclusive access

        // Produce the item
        printf("\nEnter an item: ");
        scanf("%d", &item);
        buffer[in] = item;  // Add item to the buffer
        printf("Produced item: %d at position %d\n", item, in);

        // Update 'in' index using modulo for circular buffer
        in = (in + 1) % BUFFERSIZE;

        signal(&mutex);  // Unlock the buffer
        signal(&full);   // Signal that one more slot is now full
    }
}

// Consumer function: Removes items from the buffer
void consumer() {
    if (out < in) {  // Check if more items need to be consumed
        wait(&full);  // Wait until a full slot is available
        wait(&mutex);  // Lock the buffer to ensure exclusive access

        // Consume the item
        int item1 = buffer[out];
        printf("Consumed item: %d from position %d\n", item1, out);

        // Update 'out' index using modulo for circular buffer
        out = (out + 1) % BUFFERSIZE;

        signal(&mutex);  // Unlock the buffer
        signal(&empty);  // Signal that one more slot is now empty
    }
}

// Main function: Controls the producer-consumer execution
int main() {
    printf("Enter the number of items to produce and consume: ");
    scanf("%d", &n);  // Read the number of items to produce and consume

    // Produce 'n' items
    while (in < n) {
        producer();  // Call producer function
    }

    // Consume the produced items
    while (out < in) {
        consumer();  // Call consumer function
    }

    return 0;
}
