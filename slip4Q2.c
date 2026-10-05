// Write a C program to illustrate the concept of orphan process. Parent process
// creates a child and terminates before child. So child process becomes orphan
// process. (Use fork(), sleep(), getpid(), getppid()). 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
pid_t pid;
    pid=fork();

    if(pid==0){
        printf("i am child process and my id: %d \n",getpid());
        printf("parent process id: %d \n",getppid());
        sleep(5);

        printf("after terminating parent.\n");
        printf(" new parent process id: %d \n",getppid());
        
    }
    else{
         printf("i am parent process  id : %d\n",getpid());

         sleep(2);
         printf("parent is terminating......\n");
    }

    return 0;

}
