#include<stdio.h>
#include <stdlib.h>
int main(int argc ,char*argv[]){
    int num;
    int fact=1;
    int i;

    num=atoi(argv[1]);

    for(i=1;i<=num;i++){
        fact=fact*i;
    }

    printf("factorial of %d num is %d .\n",num,fact);

    return 0;
}