//  Write the program to simulate First come first serve CPU-scheduling algorithm.
// Accept number of processes, n, from user. Take arrival time and CPU-burst time
// for n processes as input from the user. The output should be a Gantt chart, showing
// the scheduling of the processes according to First come first serve scheduling
// algorithm.

//for this: step1-take n number
//step-2 take arrival time and burst time 
//step-3 sort them
//step-4 use gantt chart logic
//step 5 print gantt chart

#include<stdio.h>
int main(){
    int n,temp,i,j;
    int at[20],bt[20],gt[20];
    int pid[20];

    printf("enter n number: \n");
    scanf("%d",&n);

    printf("enter %d numbers-\n",n);
    for(i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter arrival time for element %d: \n",i+1);
        scanf("%d",&at[i]);

        printf("enter burst time for element %d: \n",i+1);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                temp=gt[j];
                gt[j]=gt[j+1];
                gt[j+1]=temp;
            }
        }
    }

    gt[0]=at[0]+bt[0];

    for(i=0;i<n;i++){
        if(gt[i-1]<at[i]){
            gt[i]=at[i]+bt[i];
        }else{
           gt[i]= gt[i-1]+bt[i];
        }
    }
        printf("Ganttt chart\n");
        for(i=0;i<n;i++){
            printf("-----------");
        }

        printf("\n");

        for(i=0;i<n;i++){
            printf("| P%d",pid[i]);
        }

          printf("\n");

          for(i=0;i<n;i++){
            printf("-----------");
        }
        printf("\n");
        printf("%d",at[0]);//why this 

        for(i=0;i<n;i++){
            printf("          %d",gt[i]);
        }

        printf("\n");

    return 0;
}
