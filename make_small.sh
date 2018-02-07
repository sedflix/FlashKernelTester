echo "---------------------------"
echo "STARTING TO BUILD THE KERNEL"
echo "---------------------------"

# cp /workdir/config /shared_kernel/.config
cd /shared_kernel/ && \
make $1 -j4

echo "---------------------------"
echo "THE KERNEL IS BUILD"
echo "---------------------------"