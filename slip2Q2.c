// Write a program that demonstrates the use of signal() and kill() system call. Create
// a process which indicates that it wants to catch an interrupt signal, then creates a
// child process and suspends its execution till it receives a signal. Child process
// sends interrupt signal to parent process. 

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void handler(int sg){
    printf("Parent recevies the interrupt signal.\n");
}

int main(){
int pid;
signal(SIGINT,handler);

pid=fork();

if(pid==0){
    printf("child process\n");
    printf("child sending interupt signal to parent.\n");

    kill(getppid(),SIGINT);
}
else{
    printf("parent process\n");
    printf("parent waiting for signal...\n");
    pause();
}

    return 0;
}