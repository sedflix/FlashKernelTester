echo "---------------------------"
echo "STARTING TO BUILD THE KERNEL"
echo "---------------------------"

cp /workdir/config /shared_kernel/.config
cd /shared_kernel/ && \
make olddefconfig && \
make -j4

echo "---------------------------"
echo "THE KERNEL IS BUILD"
echo "---------------------------"