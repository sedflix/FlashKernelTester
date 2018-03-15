#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#define _NR_sh_task_info 314
_syscall2(long, sh_task_info, int, task_pid, char*,file_name);

int main()
{  

    char *name = "1.txt";
  
    printf("Invoking with syscall \n");
    // long int return_code_1 = syscall(314,2,name);
    long int return_code_1 = sh_task_info(64,name);
   

     if(return_code_1 == 0) {
        
        printf("Sucessful execution of syscall\n");
        printf("Opening file to read the written text by syscall\n");
        
        FILE *file = fopen(name,"r"); // read mode

        // check we opened the files
        if( file == NULL ){
            perror("Error while opening the file.\n");
            exit(EXIT_FAILURE);
        }

        printf("\n-Printing file content-\n");
        char ch;
        while( ( ch = fgetc(file) ) != EOF ){
            printf("%c",ch);
        }
        printf("\n-Done with the printing-\n");

    } else {
         perror("System call did not execute as expected\n");
    }
  
     return 0;
}
