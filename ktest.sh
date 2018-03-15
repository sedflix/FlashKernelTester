#!/bin/bash

KERNEL_SOURCE=/home/sid/Study/SEM4/OS/os-w18-kernel/linux-3.19/ 
TEST_SOURCE=$PWD/hello_world_test

if [ "$1" == "make1" ]; then
    docker run -it -v $KERNEL_SOURCE:/shared_kernel geeksid/kernel_tester bash ./make_first.sh
elif [ "$1" == "makes" ]; then
    docker run -it -v $KERNEL_SOURCE:/shared_kernel geeksid/kernel_tester bash ./make_small.sh $2
elif [ "$1" == "test" ]; then
    docker run  --privileged -it -v $KERNEL_SOURCE:/shared_kernel/ -v $TEST_SOURCE:/test/ geeksid/kernel_tester bash ./test.sh
else
    echo "WTF was that?"
fi
