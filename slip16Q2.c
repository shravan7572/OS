// Write a C Program to create a child process using fork(). First child process will
// display the message “I am Child Process” and will display its own process id and
// process id of parent process. Then parent process will display “I am Parent Process”
// and its own process id
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    pid=fork();

    if(pid==0){
        printf("i am child processs.\n");
        printf("my process id: %d\n",getpid());
        printf("my parent process id: %d\n",getppid());
    }else{
        printf("i am parent processs.\n");
        printf("my process id: %d\n",getpid());
    }
    return 0;
}