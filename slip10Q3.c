// Write a C program in which a process creates 10 child processes. Each child process
// prints its own process id and terminates. Parent process waits for termination of all
// child processes and then terminates by printing its own process id.
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
  

    for(int i=0;i<10;i++){
          pid=fork();
        if(pid==0){
            printf("i am child process . my id: %d\n",getpid());
            return 0;
        }
        
    }

    for(int i=0;i<10;i++){
        wait(NULL);
    }
    printf("i am parent process id: %d\n",getpid());
    return 0;
}
