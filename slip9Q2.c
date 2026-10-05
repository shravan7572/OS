// Write a C program in which a process creates a child process and waits for the
// termination of it. The child process prints its own process id and then executes some
// another program. On continuing execution after the child terminates, parent prints
// the process id of child which has terminated. 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    int status;

    pid=fork();
    if(pid==0){
        printf("I am child process.\n");
        printf("child process id: %d\n",getpid());

        execl("/bin/ls","ls",NULL);

        printf("execl failed.\n");
    }
    else{
        wait(&status);

        printf("child process is terminated\n");
        printf("terminated child process id: %d\n",pid);
    }
    return 0;
}