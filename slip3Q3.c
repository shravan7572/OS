// Write the program to simulate First come first serve CPU-scheduling algorithm.
// Accept number of processes, n, from user. Take arrival time and CPU-burst time
// for n processes as input from the user. The output should be a Gantt chart, showing
// the scheduling of the processes according to First come first serve scheduling
// algorithm. Also, the program should calculate waiting time, turnaround time for
// each process, and average waiting time and average turnaround time.
#include <stdio.h>
int main()
{
    int i, j, temp, n;
    int at[20], bt[20], ct[20];
    int tat[20], wt[20], pid[20];
    float avgwt = 0, avgtat = 0;

    printf("enter n number: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        pid[i] = i + 1;

        printf("Enter arrival time : \n");
        scanf("%d", &at[i]);

        printf("Enter burst time : \n");
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++)
    {
        if (ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgtat += tat[i];
        avgwt += wt[i];
    }

    // ganttt chart;

    for (i = 0; i < n; i++)
    {
        printf("----------------------");
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("|P%d ", pid[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("----------------------");
    }
    printf("\n");

    printf("%d", at[0]);

    for (i = 0; i < n; i++)
    {
        printf("%d ", ct[i]);
    }
    printf("\n");


    printf("Processs\tat\tbt\twt\ttat\n");
    for(i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],wt[i],tat[i]                
    );
    }
    printf("average turn around time: %.2f \n",avgtat/n);
    printf("average waiting  time: %.2f \n",avgwt/n);


}
