// Write a C program to illustrate the concept of orphan process. Parent process creates
// a child and terminates before child has finished its task. So child process becomes
// orphan process. (Use fork(), sleep(), getpid(), getppid()). 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid=fork();

    if(pid==0){
        printf("i am child process.\n");
        printf("my process id: %d \n",getpid());
        printf("my parent id: %d\n",getppid());

        sleep(5);
        printf("after terminating..my new parent: %d",getppid());
    }
    else{
          printf("i am parent process.\n");
        printf("my process id: %d \n",getpid());
        printf("terminating parent process.....\n");
        sleep(2);
    }
}