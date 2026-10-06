// Write a C program to accept n integers to be sorted. Executing process creates a
// child process using fork() system call. Parent process waits for child process using
// wait() system call. Child process sorts the integers using insertion sort and display
// the sorted numbers.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int i,j,key,temp,n;
    int a[100];

    printf("enter n number: \n");
    scanf("%d",&n);

    printf("enter %d number.\n",n);

    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }

    pid_t pid;
    pid=fork();
    
    if(pid==0){
        //insertion sort;
        for(i=1;i<n;i++){
            key=a[i];
            j=i-1;

            while(j>=0&&a[j]>key){
                a[j+1]=a[j];
                j--;
            }

            a[j+1]=key;
        }

        printf("insertion sort.\n");

        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }

        printf("\n");
    }else{
       
        wait(NULL);
         printf("i am parent process.\n");
          printf("waited for child process to complete the task.\n");
    }
    return 0;
}