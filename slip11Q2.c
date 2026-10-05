// Write a C Program to create a child process using fork(). Child process will display
// the message “I am Child Process”, its own process id and process id of parent and
// the parent process should display “I am Parent Process”, its own process id and
// process id of child process. 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    pid=fork();

    if(pid==0){
        printf("I am child process.\n");
        printf("My processs id : %d\n",getpid());
        printf("my parent process id: %d\n",getppid());
    }
    else{
        printf("I am parent process.\n");
        printf("My process id: %d\n",getpid());
        printf("my child process id: %d\n",pid);
    }

    return 0;
}