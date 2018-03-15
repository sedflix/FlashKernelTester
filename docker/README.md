# kernelTester

http://mgalgs.github.io/2015/05/16/how-to-build-a-custom-linux-kernel-for-qemu-2015-edition.html
http://www.kaizou.org/2016/09/boot-minimal-linux-qemu/

## Ubuntu ubuntu-14.04.1-server-amd64

- `qemu-img create ubuntu-14.04.1-server-amd64.img 50G`
  - 50G is 50GB. The size of the hard disk,  
  - name of the hardisk file is ubuntu-14.04.1-server-amd64.iso   
- `qemu-system-x86_64 -enable-kvm -m 3024 -cdrom ubuntu-14.04.1-server-amd64.iso -name mac -hda ubuntu-14.04.1-server-amd64.img`
  - boots the vm with memory of 3024 MB using OS image file ubuntu-14.04.1-server-amd64.iso and hardisk file ubuntu-14.04.1-server-amd64.iso 
- now install your first ubuntu system without worrying about your PC getting fucked up


Lets assume that that path of your complied kernel is `~/linux-master/arch/x86_64/boot/bzImage`
```
qemu-system-x86_64 -kernel ~/linux-master/arch/x86_64/boot/bzImage \
-enable-kvm \        
-append "root=/dev/sda1 panic=1" \                                                    
-hda ubuntu-14.04.1-server-amd64.img \                                                     
-enable-kvm \                                                                      
-no-reboot \                                                                       
-m 2014             
```

###Stuffs that are not ubuntu

#### Making ubuntu using debootstrap

```
IMG=qemu-image.img
DIR=mount-point.dir
qemu-img create $IMG 1g
mkfs.ext2 $IMG
mkdir $DIR
sudo mount -o loop $IMG $DIR
sudo debootstrap  --arch amd64 trusty $DIR http://archive.ubuntu.com/ubuntu/
sudo umount $DIR
rmdir $DIR
```

Repalce "trusty $DIR http://archive.ubuntu.com/ubuntu/" with the version and os you want to install. Google for availibity.

Run it using:

```

qemu-system-x86_64 -kernel ~/linux-master/arch/x86_64/boot/bzImage    \
-append "root=/dev/sda single console=ttyS0 panic=1" \
-hda ~/Study/SEM$/OS/ktest-doc/qemu-image.img \
-enable-kvm \
-no-reboot \
-nographic 

```


#### The most minimal image possible

```
qemu-system-x86_64 -kernel ~/linux-master/arch/x86_64/boot/bzImage    \
-append "root=/dev/sda console=ttyS0 panic=1" \
-hda ~/linux-master/core-image-minimal-qemux86-64.ext4 \
-enable-kvm \
-no-reboot \
-nographic 
```


