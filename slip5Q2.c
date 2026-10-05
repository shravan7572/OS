//  Implement the C Program to create a child process using fork(). Child process will
// display the message “I am Child Process” and the process id of its parent. The
// parent process should display “I am Parent Process” and its own process id. 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid=fork();

    if(pid==0){
        printf("I am child process.\n");
        printf("my process id is: %d\n",getpid());
        printf("my parent process id : %d\n",getppid());
    }else{
         printf("I am parent process.\n");
        printf("my process id is: %d\n",getpid());
    }

    return 0;
}