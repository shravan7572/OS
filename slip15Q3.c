// Write a C program that accepts an integer value. Executing process creates a child
// process. Parent process passes this integer value to child process through the
// arguments of execl() system call which the child process executes. The program
// which child process executes, calculate the square of the number passed to it. 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int n;
    char str[20];
    printf("Enter number : \n");
    scanf("%d",&n);

    pid_t pid;
    pid=fork();
    if(pid==0){
        sprintf(str ,"%d",n);
        execl("./square","square",str,NULL);
    }
    return 0;
}
