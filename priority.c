#include <stdio.h>

int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    // Input number of processes
    printf("Enter the number of processes --- ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for (i = 0; i < n; i++) {
        p[i] = i; // Store process numbers
        printf("Enter the Burst Time & Priority of Process %d --- ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sort processes based on priority (higher priority executed first)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap process numbers
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap priorities
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    // Initialize waiting time and turnaround time for the first process
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    // Calculate waiting time and turnaround time for other processes
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time
        tat[i] = tat[i - 1] + bt[i];   // Turnaround time
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Print process details
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    // Print average waiting time and turnaround time
    printf("\nAverage Waiting Time is --- %f", wtavg / n);
    printf("\nAverage Turnaround Time is --- %f", tatavg / n);

    return 0;
}









Enter the number of processes --- 4
Enter the Burst Time & Priority of Process 0 --- 6
3
Enter the Burst Time & Priority of Process 1 --- 2
2
Enter the Burst Time & Priority of Process 2 --- 14
1 
Enter the Burst Time & Priority of Process 3 --- 6
4

PROCESS         PRIORITY        BURST TIME      WAITING TIME    TURNAROUND TIME
2                1               14              0               14
1                2               2               14              16
0                3               6               16              22
3                4               6               22              28
Average Waiting Time is --- 13.000000
Average Turnaround Time is --- 20.000000
