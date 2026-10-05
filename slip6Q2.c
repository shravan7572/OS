// Write a program that demonstrates the use of signal() and kill() system call. Create
// a process which indicates that it wants to catch a user defined signal, then creates a
// child process and suspends its execution till it receives a signal. Child process sends
// user defined signal to parent process. 
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
void handler(int sig){
    printf("parent received the interrupt signal");
}

int main(){
    pid_t pid;
    pid=fork();

    signal(SIGUSR1, handler);

    if(pid==0){
        printf("i am child process\n");
        printf("sending interupt signal to parent\n");

        kill(getppid(),SIGUSR1);
    }
    else{
        printf("i am parent processs.\n");
        printf("parent waiting for signal\n");
        pause();
    }
return 0;
}