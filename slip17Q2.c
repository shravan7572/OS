// Implement the C Program that creates a child process using fork(). Parent process
// displays the message “I am Parent of Process : ” and prints process id of child
// process. Child process will display the message “I am Child of Process : ” and prints
// // the process id of parent. 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    pid= fork();

    if(pid==0){
        printf("i am child process.my parent id: %d",getppid());
    }
    else{

         printf("i am parent process.my child id: %d",pid);
    }
    return 0;
}