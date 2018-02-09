FROM ubuntu:xenial
MAINTAINER Siddharth Yadav

ENV ETCDCTL_VERSION v3.0.12
ENV ETCDCTL_ARCH linux-amd64
ENV DEBIAN_FRONTEND noninteractive

RUN apt-get -y update
RUN apt-get -y upgrade

# Install QEMU/KVM
RUN apt-get -y install qemu-kvm

# Install Ceph common utilities/libraries
RUN apt-get -y install ceph-common wget

# Install etcdctl
RUN wget -q -O- "https://github.com/coreos/etcd/releases/download/${ETCDCTL_VERSION}/etcd-${ETCDCTL_VERSION}-${ETCDCTL_ARCH}.tar.gz" |tar xfz - -C/tmp/ etcd-${ETCDCTL_VERSION}-${ETCDCTL_ARCH}/etcdctl
RUN mv /tmp/etcd-${ETCDCTL_VERSION}-${ETCDCTL_ARCH}/etcdctl /usr/local/bin/etcdctl

RUN apt-get install -yf build-essential qemu-system-x86 \
                                        make \
                                        gcc-4.8 \
                                        unzip \
					git
RUN apt-get install -yf  libelf-dev \ 
                                        chrpath \
                                        gawk \
                                        texinfo \
                                        libsdl1.2-dev \
                                        whiptail \
                                        diffstat \
                                        cpio \
                                        libssl-dev \
                                        bc
  
RUN apt-get install -y nano \
			minicom


RUN rm -rf /var/lib/apt/lists/*

COPY . /workdir
RUN chmod +x /workdir/*.sh

RUN mkdir /shared_kernel
RUN mkdir /test
VOLUME ["/shared_kernel","/test"] 

WORKDIR /workdir
