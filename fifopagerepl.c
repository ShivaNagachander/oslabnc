#include<stdio.h>
int main() 
{ 
    int a[5], b[20], n, p = 0, q = 0, m = 0, h, k, i, q1 = 1; 
    char f = 'F'; 
    printf("Enter the Number of Pages: "); 
    scanf("%d", &n); 
    printf("Enter %d Page Numbers: ", n); 
    for(i = 0; i < n; i++) 
        scanf("%d", &b[i]); 
    for(i = 0; i < n; i++) 
    { 
        if(p == 0) 
        { 
            if(q >= 3) 
                q = 0; 
            a[q] = b[i]; 
            q++; 
            if(q1 < 3) 
                q1 = q; 
        } 
        printf("\n%d\t", b[i]); 
        for(h = 0; h < q1; h++) 
            printf("%d ", a[h]); 
        if((p == 0) && (q <= 3)) 
        { 
            printf("--> %c", f); 
            m++; 
        } 
        p = 0; 
        for(k = 0; k < q1; k++) 
        { 
            if(b[i + 1] == a[k]) 
                p = 1; 
        } 
    } 
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
