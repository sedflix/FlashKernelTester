FROM ubuntu:16.04
MAINTAINER Siddharth Yadav

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends apt-utils
RUN apt-get install -yf build-essential qemu-system-x86 qemu-system-arm \
                                        qemu-kvm \
                                        make \
                                        gcc \
                                        unzip \
                                        wget \ 
                                        qemu \
                                        virt-manager
RUN apt-get install -y virt-viewer libvirt-bin \
                                        libelf-dev \ 
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
