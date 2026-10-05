// Implement the C program to accept n integers to be sorted. Main function creates
// child process using fork system call. Parent process sorts the integers using bubble
// sort and waits for child process using wait system call. Child process sorts the
// integers using insertion sort. Both parent and child display the name of sorting
// method used and the data in sorted order. 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){

    int i,j,key,temp,n;
    int a[100],b[100];

    printf("enter n number: \n");
    scanf("%d",&n);

    printf("enter %d elements: \n",n);
    for(i=0;i<n;i++){
        printf("enter element no %d: ",i+1);
        scanf("%d",&a[i]);
        b[i]=a[i];
    }

    pid_t pid;
    pid=fork();

    if(pid==0){
        //insertion sort.

        for(i=1;i<n;i++){
            key=b[i];
            j=i-1;

            while(j>=0&&b[j]>key){
                b[j+1]=b[j];
                j--;
            }
            b[j+1]=key;
        }

        printf("Insertion sort.\n");

        for(i=0;i<n;i++){
            printf("%d",b[i]);
        }
        printf("\n");
    }else{
        //bubble sort.

        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }

        printf("Bubble sort.\n");
        for(i=0;i<n;i++){
            printf("%d",a[i]);
        }
        printf("\n");
        wait(NULL);
    }
            
    return 0;
}
