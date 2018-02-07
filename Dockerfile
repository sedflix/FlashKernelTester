FROM tianon/qemu
MAINTAINER Siddharth Yadav


RUN apt-get update && apt-get install -y --no-install-recommends apt-utils

RUN apt-get install -yf build-essential qemu-system-x86
                                        qemu-kvm \
                                        make \
                                        gcc \
                                        unzip \
                                        wget
  
RUN apt-get install -y nano \
			minicom


RUN rm -rf /var/lib/apt/lists/*

RUN mkdir /shared
VOLUME ["/shared"] 
WORKDIR /shared

RUN git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git

# RUN IMG=qemu-image.img && \
# 	DIR=mount-point.dir && \
# 	qemu-img create $IMG 1g && \
# 	mkfs.ext2 $IMG && \
# 	mkdir $DIR && \
# 	mount -o loop $IMG $DIR && \
# 	debootstrap  --arch amd64 trusty $DIR http://archive.ubuntu.com/ubuntu/ && \
# 	umount $DIR && \
# 	rmdir $DIR \

