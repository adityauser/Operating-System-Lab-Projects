#include<stdio.h>
int main()
{
    int bt[5],p[5],wt[5],tat[5],pr[5],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    int y=0;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    printf("Enter 'y' option:");
    scanf("%d", &y);
    if(y) {
        printf("\nEnter Burst Time and Priority\n");
        for(i=0;i<n;i++) {
            printf("\nP[%d]\n",i+1);
            printf("Burst Time:");
            scanf("%d",&bt[i]);
            printf("Priority:");
            scanf("%d",&pr[i]);
            p[i]=i+1;           
        }
    }
    else {
        for(int i=0; i<n;i++) {
            p[i] = i+1;
            bt[i] = i + 2;
            pr[i] = i%2;
        }
    }

    for(i=0;i<n;i++) {
        pos=i;
        for(j=i+1;j<n;j++) {
            if(pr[j]<pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++) {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/(float)n;      
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/(float)n;     
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
 
	return 0;
}