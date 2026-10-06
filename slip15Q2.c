// Write a C program to simulate FCFS scheduling algorithm. The arrival time and
// CPU-burst time for n number of processes should be input to the program. The
// output should give turnaround time and waiting time for each process. 
#include<stdio.h>
int main(){
    int i,j,temp,n;
    int at[10],bt[20],ct[20],tat[20],wt[20],pid[20];

    printf("Enter n number: \n");
    scanf("%d",&n);

    printf("Enter %d elementL \n",n  );

    for(i=0;i<n;i++){
        pid[i]=i+1;

        printf("enter arrival time for %d process: ",i+1);
        scanf("%d",&at[i]);

        printf("enter burst time for %d process: ",i+1);
        scanf("%d",&bt[i]);
    }
    //sorting 
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(at[j+1]<at[j]){
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                 temp=pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=temp;
            }
        }
    }

    //completion time;
    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++){
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
        }
        else{
            ct[i]=ct[i-1]+bt[i];
        }
    }

    //waiting time and turnaroundtime.

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]=bt[i];
    }

    printf("\nprocess\tAT\tBT\tTAT\tWT.\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],tat[i],wt[i]);
    }
    return 0;
}