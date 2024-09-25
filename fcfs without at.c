#include<stdio.h> 
void main() 
{ 
    int i, n; 
    printf("enter number of processes : \n"); 
    scanf("%d", &n); 
    int b[n], arr[n], com[n], tur[n], w[n]; 
    float avg, t; 
    printf("enter burst times of each process : \n"); 
    for(i = 0; i < n; i++) 
    { 
        scanf("%d", &b[i]); 
    } 
    for(i = 0; i < n; i++) 
    { 
        arr[i] = 0; 
    } 
    int s = 0; 
    for(i = 0; i < n; i++) 
    { 
        com[i] = s + b[i]; 
        s = com[i]; 
    } 
    s = 0; 
    for(i = 0; i < n; i++) 
    { 
        tur[i] = com[i] - arr[i]; 
        s += tur[i]; 
    } 
    t = (float)s / n; 
    s = 0; 
    for(i = 0; i < n; i++) 
    { 
        w[i] = tur[i] - b[i]; 
        s += w[i]; 
    } 
    avg = (float)s / n; 
    printf("process\tarrival\tcompletion\tturn around\tburst\twaiting\n"); 
    for(i = 0; i < n; i++) 
    { 
        printf("    %d\t   %d\t    %d\t\t   %d\t\t  %d\t    %d\n", i + 1, arr[i], com[i], tur[i], b[i], w[i]); 
    } 
    printf("average waiting time : %.2f\n", avg); 
    printf("average turn around  : %.2f\n", t); 
}




enter number of processes : 
3
enter burst times of each process : 
24
3
2
process arrival completion      turn around     burst   waiting
    1      0        24             24             24        0
    2      0        27             27             3         24
    3      0        29             29             2         27
average waiting time : 17.00
average turn around  : 26.67








