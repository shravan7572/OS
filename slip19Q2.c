//  Write a C program to accept n integers to be sorted. Executing process creates a child
// process using fork() system call. Child process sorts the integers using bubble sort.
// Parent process waits for the termination of child and then prints exit status of child
// and terminates.
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){

    int i,j,temp,n;
    int a[100];
    int status;

    printf("enter n number: \n");
    scanf("%d",&n);

    printf("enter %d elements.\n",n);

    for(i=0;i<n;i++){
        printf("element %d: \n",i+1);
        scanf("%d",&a[i]); 
    }

    pid_t pid;
    pid=fork();

    if(pid==0){
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }

        printf("child processs.\n");
        printf("bubble sort\n");
        
        for(i=0;i<n;i++){
            printf("%d",a[i]);
        }
        printf("\n");

        return  6;
    }else{
        wait(&status);
        printf("parent processs\n");

        if(WIFEXITED(status)){
            printf("child process exited with %d status \n",WEXITSTATUS(status));
        }

    }

    return 0;
}