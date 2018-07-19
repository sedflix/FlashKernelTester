#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
void intensive_loop(int k){
        printf("In Child: %d: before loop %d\n", getpid(),k);

        // some intensive task
        volatile unsigned long long i;
        for (i = 0; i < 1000000000ULL; ++i) {
            if(i%10000000 == 0){
                printf("-:-");
            }
        }
        printf("\nIn Child: %d: after loop %d\n", getpid(),k);
}

void lol() {

    printf("\nLOL\n");
    int waitime = 10000;
    // long int return_code_1 = syscall(323,14,waitime);

    pid_t pid;
    printf("LOL process parents pid: %d\n", getpid());
    
    pid = fork();
    
    if(pid == 0) {
        printf("In Child: %d\n", getpid());
        
        intensive_loop(1);
        intensive_loop(2);
        intensive_loop(3);
        
        printf("In Child: %d : Final statement\n", getpid());
        
        exit(1);

    } else {
        printf("In Parent: %d \n", getpid());


        printf("In Parent: %d: before syscall\n", getpid());
        // increase rtnice of child process
        syscall(323, pid,waitime);
        printf("In Parent: %d: after syscall\n", getpid());


        printf("In Parent: %d: after syscall check\n", getpid());
        wait(NULL);
        printf("In Parent: %d: after WAIT: \n", getpid());
    }
}

int main()
{  

   int waitime = 10000;
    // long int return_code_1 = syscall(323,14,waitime);

    pid_t pid;
    printf("parent : %d\n", getpid());
    
    pid = fork();
    
    if(pid == 0) {
        printf("In Child: %d\n", getpid());

        intensive_loop(1);
        intensive_loop(2);
        intensive_loop(3);
        
        printf("In Child: %d : Final statement\n", getpid());
        
        exit(1);

    } else {
        printf("In Parent: %d \n", getpid());


        printf("In Parent: %d: before syscall\n", getpid());
        // increase rtnice of child process
        syscall(323, pid,waitime);
        printf("In Parent: %d: after syscall\n", getpid());


        printf("In Parent: %d: after syscall check\n", getpid());
        wait(NULL);
        printf("In Parent: %d: after WAIT: \n", getpid());
    }
    return 0;
}
