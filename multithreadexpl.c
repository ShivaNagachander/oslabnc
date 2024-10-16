#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  // Required for using pthreads

// Thread function that prints a message with the thread ID
void* print_message(void* thread_id) {
    long tid = (long) thread_id;  // Convert thread ID back to long
    printf("Hello from thread %ld!\n", tid);  // Print the message with thread ID
    pthread_exit(NULL);  // Exit the thread
}

int main() {
    pthread_t threads[2];  // Array to store thread IDs (2 threads)
    int rc;  // Return code to check thread creation success
    long t;  // Variable to store thread ID

    // Create 2 threads
    for (t = 0; t < 2; t++) {
        printf("Main: creating thread %ld\n", t);  // Log thread creation
        rc = pthread_create(&threads[t], NULL, print_message, (void*)t);  // Create thread

        // Check if thread creation was successful
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);  // Print error if failed
            exit(-1);  // Exit program with error code
        }
    }

    // Wait for both threads to complete
    for (t = 0; t < 2; t++) {
        pthread_join(threads[t], NULL);  // Block until thread 't' finishes
    }

    // Print final message after all threads have completed
    printf("Main: All threads completed. Exiting.\n");
    return 0;
}
