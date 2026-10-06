// Write a C program that accepts an integer value. Executing process creates a child
// process. Parent process passes this integer value to child process through the
// arguments of execl() system call which the child process executes. The program
// which child process executes, calculate the factorial of the number passed to it.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int n;
    char str[30];
 pid_t pid;
    printf("enter a number: \n");
    scanf("%d",&n);

   

    pid=fork();

    if(pid==0){
        sprintf(str,"%d",n);

        execl("./fact","fact",str,NULL);
        printf("execl failed\n");
    }
    return 0;
}