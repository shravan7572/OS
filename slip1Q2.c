//  Implement the C Program to create a child process using fork(), display parent
// and child process id. Child process will display the message “I am Child Process”
// and the parent process should display “I am Parent Process”. 

#include<stdio.h>
#include <unistd.h>

int main(){
    int pid;
    pid=fork();

    if(pid==0){
        printf("i am child processs.\n");
        printf("my process id: %d\n",getpid());
         printf("Parent Process ID = %d\n", getppid());
    }

    else{
         printf("i am parent processs.\n");
        printf("my process id: %d\n",getppid());
    }
    return 0;
}
