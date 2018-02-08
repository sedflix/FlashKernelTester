# ktester 

This is my attempt to make compiling of custom linux kernel(for kernel dev) followed by their super fast testing while booting. All this has been made as easy as possible. 

## Prereq:

- Install docker on your system (The downside. You have yo install this)
  - For Ubuntu: https://docs.docker.com/install/linux/docker-ce/ubuntu/#install-docker-ce-1
  - For Windows 10: https://docs.docker.com/docker-for-windows/install/#what-to-know-before-you-install
- [Optional] Check your installation of docker using -
  - `sudo docker run -it ubuntu` (for windows)
  - This will take some time as it will download ubuntu image.
  - It will change your prompt to something like `root@4d4c9750e9e0:/#`. This is the shell of an full fledged ubuntu running on docker.
- You should have downloaded your linux kernel on your system (>v4.0. Tested on v4.15 and v4.9)
- Make the test file required to run on bootup(This is the only code that will run) and store it in a folder with name of the `.c` file as `test.c`
  
  
## Usage: 

- Clone this repo on your system using: git clone https://github.com/geekSiddharth/kernelTester.git

- Open ktest.sh to edit the following variable
    - KERNEL_SOURCE
        It refers to the absolute linux kernal path. (Path should end in /)  
        Example: `KERNEL_SOURCE=/home/sid/linux-master/` where `/home/sid/linux-master/` is the absolute linux kernal path
    - TEST_SOURCE
        It refers to the absolute path of testing code. (Path should end in /)    
        The pointed folder must constain a file called test.c 
        (You can leave it to its default value for seeing if everything is working fine)

-  Make ktest.sh executable by using: `chmod +x ktest.sh`

- If you are making the kernel for the first time, use:
    ```
    ./ktest.sh make1
    ```

    Note this may take A LOT OF TIME if you are executing ktest.sh for the first time on you system.

- To test the image and the kernel, use:
    ```
    ./ktest.sh test
    ```

- If you want to recompile on a part of kernel which *resides in a folder with relative path within the linux folder as ./fold*, use this to build,
    ```
    ./ktest.sh makes ./fold
    ```
    
    This is much faster.

### ?

##### Why so fast?

- We are not building the whole kernel. `config` file in `docker/` stores aprx minimum configurations.
    - drastically reduces building time
    - fast bootup time
- `makes` only builds the folder. If you are making changes to the sys call, whose code reside in particular folder, it is much faster to use `makes <relative(to Linux Source folder) path to the folder>`
- The building is done on the docker platform, which has almost no performace overhead. Therefore full utilization of your system resources and hence much faster booting time(than building inside a slow VM)

##### Why so fast?

You remember the init process? It is the first process to be executed. Before init starts to execute , the kernel is executing. The test.c file is changed to a static binary and is passed to the kernel as the init process. The kernel executes the the static binary and it exits.