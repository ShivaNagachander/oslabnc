#include <stdio.h>

int main() {
    // Variable declarations
    int n, bt[10], tq, i, et = 0, tbt = 0, c[10], b[10], twt = 0, w[10], count = 0;
    float avgwt, avgtt;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get the burst times for each process
    printf("Enter %d burst times: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // Get the time quantum
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    // Initialize tracking arrays and calculate total burst time
    for (i = 0; i < n; i++) {
        b[i] = 0;  // Store the total time executed for each process
        w[i] = 0;  // Store the waiting time for each process
        c[i] = 0;  // Store the completion time for each process
        tbt = tbt + bt[i];  // Sum of all burst times (used for avg turnaround time)
    }

    // Main loop for Round Robin scheduling
    for (i = 0; count != n;) {  // Continue until all processes are completed
        if (bt[i] < 0) {
            // Error check if burst time is negative (should not happen in a valid scenario)
            printf("error");
        } 
        else if (bt[i] > 0) {
            if (bt[i] > tq) {  
                // If burst time is greater than time quantum, reduce it by tq
                bt[i] = bt[i] - tq;
                et = et + tq;  // Increase elapsed time
                b[i] = b[i] + tq;  // Track the total executed time for the process
            } 
            else {
                // If burst time is less than or equal to time quantum, complete the process
                et = et + bt[i];  // Add remaining burst time to elapsed time
                b[i] = b[i] + bt[i];  // Track total executed time for the process
                bt[i] = 0;  // Mark the process as completed
                c[i] = et;  // Store the completion time
                count++;  // Increase the count of completed processes
            }
        }
        
        // Move to the next process in a cyclic manner
        i++;
        if (i >= n)  // Reset to the first process after reaching the end
            i = 0;
    }

    // Calculate waiting times for all processes
    for (i = 0; i < n; i++) {
        w[i] = c[i] - b[i];  // Waiting time = Completion time - Executed time
        twt = twt + w[i];  // Total waiting time for all processes
    }

    // Calculate average turnaround time and waiting time
    avgtt = (float)(tbt + twt) / n;  // Avg turnaround time = (Total burst time + Total waiting time) / n
    avgwt = (float)twt / n;  // Avg waiting time = Total waiting time / n

    // Print the results
    printf("\n Total Waiting Time: %d", twt);
    printf("\n Average Turn Around Time: %f", avgtt);
    printf("\n Average Wait Time: %f", avgwt);

    return 0;
}
