#include <stdio.h>

int main() 
{ 
    // a[] holds pages in frame, b[] holds input page sequence
    int a[5], b[20], n, p = 0, q = 0, m = 0, h, k, i, q1 = 1; 
    char f = 'F';  // 'F' denotes a page fault

    // Input: Number of pages
    printf("Enter the Number of Pages: "); 
    scanf("%d", &n); 

    // Input: Page numbers in the sequence
    printf("Enter %d Page Numbers: ", n); 
    for (i = 0; i < n; i++) 
        scanf("%d", &b[i]); 

    // Start processing each page in the sequence
    for (i = 0; i < n; i++) 
    { 
        // If page is not found in frame (p == 0)
        if (p == 0) 
        { 
            // If frame is full, reset position to 0 (FIFO logic)
            if (q >= 3) 
                q = 0; 

            // Insert the new page into the frame
            a[q] = b[i]; 
            q++; 

            // Adjust frame size counter if it's not yet full
            if (q1 < 3) 
                q1 = q; 
        } 

        // Display the current page and the contents of the frame
        printf("\n%d\t", b[i]); 
        for (h = 0; h < q1; h++) 
            printf("%d ", a[h]); 

        // If a page fault occurs, display 'F' and increment fault counter
        if ((p == 0) && (q <= 3)) 
        { 
            printf("--> %c", f); 
            m++;  // Increment page fault counter
        } 

        p = 0;  // Reset the 'found' flag for the next page

        // Check if the next page is already in the frame
        for (k = 0; k < q1; k++) 
        { 
            if (b[i + 1] == a[k]) 
                p = 1;  // Page is found in the frame
        } 
    } 

    // Output the total number of page faults
    printf("\nNumber of page faults: %d\n", m); 

    return 0;
}
Enter the Number of Pages: 12
Enter 12 Page Numbers: 1 2 3 4 1 2 5 1 2 3 4 5 

1	1 --> F
2	1 2 --> F
3	1 2 3 --> F
4	4 2 3 --> F
1	4 1 3 --> F
2	4 1 2 --> F
5	5 1 2 --> F
1	5 1 2 
2	5 1 2 
3	5 3 2 --> F
4	5 3 4 --> F
5	5 3 4 
Number of page faults: 9
