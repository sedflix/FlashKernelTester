echo "---------------------------"
echo "STARTING TO MAKE INIT"
echo "---------------------------"

cd /test && \
gcc -static test.c -o init  && \
echo init | cpio -o --format=newc > initramfs

echo "---------------------------"
echo "TEST INIT MADE"
echo "---------------------------"

echo "---------------------------"
echo "Going to start qemu"
echo "---------------------------"

qemu-system-x86_64 \ 
-kernel /shared_kernel/arch/x86_64/boot/bzImage  \
-initrd /test/initramfs
-append "console=ttyS0 panic=1" \
-enable-kvm \
-no-reboot \
-nographic 