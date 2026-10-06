// Write a C program to illustrate the concept of orphan process. Parent process creates
// a child and terminates before child has finished its task. So child process becomes
// orphan process. (Use fork(), sleep(), getpid(), getppid()). 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid=fork();

    if(pid==0){
        printf("i am child process.my id: %d\n",getpid());
        printf("my parent process id: %d\n",getppid());

        sleep(5);
        printf("after terminating my new parent id: %d\n",getppid());
    }else{
        printf(" i am parent process.\n");
        printf("terminating parent processs.\n");
        sleep(2);
    }
    return 0;
}
