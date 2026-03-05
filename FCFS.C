#include<stdio.h>

int main()
{
int n,i;

printf("\nenter number of process: ");
scanf("%d",&n);

int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
float total_tat=0,total_wt=0;


for (i=0;i<n;i++)
{
    pid[i]=i+1;
    printf("\nprocess ID: %d",i+1);
    printf("\nArrival Time: ");
    scanf("%d",&at[i]);
    printf("\nburst time: ");
    scanf("%d",&bt[i]);

}

for (i=0;i<n-1;i++)
{
    for (int j=i+1;j<n;j++)
    {
        if (at[i]>at[j])
        {
            int temp=at[i];
            at[i]=at[j];
            at[j]=temp;

            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;

            temp=pid[i];
            pid[i]=pid[j];
            pid[j]=temp;
        }
    }
}

ct[0]=at[0]+bt[0];
for (i=1;i<n;i++)
{
    if (ct[i-1]<at[i])
    {
        ct[i]=at[i]+bt[i];
    }
    else
    {
        ct[i]=ct[i-1]+bt[i];
    }
}

for (i=0;i<n;i++)
{
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    rt[i]=wt[i];
    total_tat+=tat[i];
    total_wt+=wt[i];
}

printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT");

for(i=0;i<n;i++)
{
    printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
}

printf("\nAVG of TAT is : %.2f",total_tat/n);
printf("\nAVG of WT is : %.2f",total_wt/n);
return 0;

}
