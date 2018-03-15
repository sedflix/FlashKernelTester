
# Assignment 2


**Name:** Siddharth Yadav
**Roll Number:** 2016268


### Usage:

The system call requires pid and the file name to which the info has to be written.
It prints(using `printk`) and write the following info:
- name of the task with the given pid  
- name of the parent process of the above task (only if it has a parent)

```

#define _NR_sh_task_info 314
_syscall2(long, sh_task_info, int, task_pid, char*,file_name);

...
...
int pid = 2;
char *file_name = "2.txt"
long int return_code = sh_task_info(pid,file_name);

```

OR

```
#include <sys/syscall.h>

...
...

int pid = 2;
char *file_name = "2.txt"
long int return_code = syscall(314,pid,file_name);
```

### Example output (kernel and console interleaved)

```
Invoking with syscall 
Process Name: kthreadd                     
Parent Process Name: swapper                
Sucessful execution of syscall              
Opening file to read the written text by syscall                                        

-Printing file content-                     
Process Name: kthreadd                     
Parent Process Name: swapper                

-Done with the printing-                    

```

### Error Handling

- ESRCH |   3   |   If no with the given pid is found process
-  -    |   600 |   If given file name is empty but process info was printed      
- If we are not able to create the file due to any reason, corresponding Linux System Errors code is returnd (Refer errno for more info)


### Implementation 

To implement a syscall following changes are required:

- Changing the root Makefile to include the directory(`task_info` in my case) so that it can go that directory to find an Makefile and build stuffs using that file and incule stuffs in final binary. 
- The folder must contain a Makefile. In my case the line is `obj-y:=task_info.o`. It says that `task_info.o` should be built from `task_info.c`(or .S).
- Changing `arch/x86/syscalls/syscall_64.tbl`: This contains a table for all syscalls(with syscall name and number) for a a given architecture. Since I've modified only the syscall table of x86 architecture, my syscall will only be availble for kernel build for x86 or x86_64 architecture. The syscall number is `314`
- Changing `include/linux/syscalls.h`: The header file for all syscalls. Function defination of all the syscalls are present here.
- All other code for the syscall are written in the a folder call `task_info` in my call.
- The syscall code is in `task_info.c`


The code is short and Invoking with syscall 
EProcess Name: kthreadd                     
Parent Process Name: swapper                
Sucessful execution of syscall              
Opening file to read the written text by syscall                                        

-Printing file content-                     
EProcess Name: kthreadd                     
Parent Process Name: swapper                

-Done with the printing-                    
it has been well documented. Hence refer to the code for more implementation details.

### Testing

A `test.c` file is provided for the same.
It invokes the system call and then read the info written in the file and prints it on the console.  

NOTE: 
- All the testing(which includes building the kernel and running `test.c`) has been done using:- https://github.com/geekSiddharth/FlashKernelTester 
- diff generated using `git diff`
- A patch has been submitted
