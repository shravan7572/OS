// Write a program that demonstrates the use of signal() and kill() system call. Create
// a process which indicates that it wants to catch an interrupt signal, then creates a
// child process and suspends its execution till it receives a signal. Child process sends
// interrupt signal to parent process. 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void handler(int sig){
    printf("parent processor receives interupt receive.\n");
}

int main(){
    pid_t pid;

    signal(SIGINT,handler);
    pid=fork();
    if(pid==0){
        printf("i am child process .\n");
        printf("sending interupt signal to parent process.\n");
        kill(getppid(),SIGINT);
    }
    else{
        printf("i am parent process.\n");
        printf("Waiting for interupt signals....\n");
        pause();
    }
    return 0;
}