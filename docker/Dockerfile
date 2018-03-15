FROM        ubuntu:xenial
MAINTAINER Siddharth Yadav

# update and install dependencies
RUN         apt-get update \
                && apt-get install -y \
                    software-properties-common \
                    wget \
                && add-apt-repository -y ppa:ubuntu-toolchain-r/test \
                && apt-get update \
                && apt-get install -y \
                    make \
                    git \
                    curl \
                    vim \
                && apt-get install -y cmake=3.5.1-1ubuntu3 \
                && apt-get install -y \
                    gcc-4.9 g++-4.9 gcc-4.9-base \
                    gcc-4.8 g++-4.8 gcc-4.8-base \
                    gcc-4.7 g++-4.7 gcc-4.7-base \
                    gcc-4.6 g++-4.6 gcc-4.6-base \
                && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 100 \
                && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 100


ENV ETCDCTL_VERSION v3.0.12
ENV ETCDCTL_ARCH linux-amd64
ENV DEBIAN_FRONTEND noninteractive

# Install QEMU/KVM
RUN apt-get -y install qemu-kvm

# Install Ceph common utilities/libraries
RUN apt-get -y install ceph-common

# Install etcdctl
RUN wget -q -O- "https://github.com/coreos/etcd/releases/download/${ETCDCTL_VERSION}/etcd-${ETCDCTL_VERSION}-${ETCDCTL_ARCH}.tar.gz" |tar xfz - -C/tmp/ etcd-${ETCDCTL_VERSION}-${ETCDCTL_ARCH}/etcdctl
RUN mv /tmp/etcd-${ETCDCTL_VERSION}-${ETCDCTL_ARCH}/etcdctl /usr/local/bin/etcdctl

RUN apt-get install -yf build-essential qemu-system-x86 \
                                        unzip \
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
