#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

void lol(){

    long long int waitime = 10;
    // long int return_code_1 = syscall(323,14,waitime);

    pid_t pid;
    printf("parent : %d\n", getpid());
    
    pid = fork();
    
    if(pid == 0) {
        printf("In Child: \n");
       
        printf("In Child: before loop\n");
        int i =0;
        while(i<10) {
           i = i + 1;
           printf("-:-");
        }
        printf("\nIn Child: after loop\n");

        printf("In Child: final statement\n");
        exit(1);

    } else {
        printf("In Parent:\n");
        int i =0;
        printf("In Parent: before syscall\n");
        syscall(323, pid,waitime);
        printf("In Parent: after syscall\n");
         //CALL SYS ALL FROM HERE
         //getpidchildren
         //syscall
         //wow
         // while(i<50000) {
         //     printf("%d ",i);
         //     i++;
         // }
         printf("In Parent: after check\n");
         wait(NULL);
         printf("In Parent: after WAIT\n");
    }
}

int main()
{  

   long long int waitime = 10;
    // long int return_code_1 = syscall(323,14,waitime);

    pid_t pid;
    printf("parent : %d\n", getpid());
    
    pid = fork();
    
    if(pid == 0) {
        printf("In Child: \n");
       
        printf("In Child: before loop\n");
        int i =0;
        while(i<10) {
           i = i + 1;
           printf("-:-");
        }
        printf("\nIn Child: after loop\n");
        lol();

        printf("In Child: final statement\n");
        exit(1);

    } else {
        printf("In Parent:\n");
        int i =0;
        printf("In Parent: before syscall\n");
        syscall(323, pid,waitime);
        printf("In Parent: after syscall\n");
        lol();
         //CALL SYS ALL FROM HERE
         //getpidchildren
         //syscall
         //wow
         // while(i<50000) {
         //     printf("%d ",i);
         //     i++;
         // }
         printf("In Parent: after check\n");
         wait(NULL);
         printf("In Parent: after WAIT\n");
    }
    return 0;
}
