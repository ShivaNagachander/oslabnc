#include<stdio.h>
int main()
{
int n,bt[10],tq,i,et=0,tbt=0,c[10],b[10],twt=0,w[10],count=0;
float avgwt,avgtt;
printf("Enter the number of processes:");
scanf("%d",&n);
printf("Enter %d burst times:",n);
for(i=0;i<n;i++)
scanf("%d",&bt[i]);
printf("Enter time quantum:");
scanf("%d",&tq);
for(i=0;i<n;i++)
{
b[i]=0;
w[i]=0;
c[i]=0;
tbt=tbt+bt[i];
}
for(i=0;count!=n;)
{
if(bt[i]<0)
{
printf("error");
}
else if(bt[i]>0)
{
if(bt[i]>tq)
{
bt[i]=bt[i]-tq;
et=et+tq;
b[i]=b[i]+tq;
}
else
{
et=et+bt[i];
b[i]=b[i]+bt[i];
bt[i]=0;
c[i]=et;
count++;
}
}
i++;
if(i>=n)
i=0;
}
for(i=0;i<n;i++)
{
w[i]=c[i]-b[i];
twt=twt+w[i];
}
avgtt=(float)(tbt+twt)/n;
avgwt=(float)twt/n;
printf("\n Total Waiting Time: %d",twt);
printf("\n Average Turn Around Time: %f",avgtt);
printf("\n Average Wait Time:%f",avgwt);
}


Enetr the number of processes:5
Enter 5 burst times:4
2
3
5
6
Enter time quantum:2
 Total Waiting Time: 47
 Average Turn Around Time: 13.400000
 Average Wait Time:9.400000
