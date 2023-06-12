repo init -u ssh://liushiwei@gerrit.eswincomputing.com:29418/platform/manifest -b a710-sdk-d_dev --repo-url=ssh://liushiwei@gerrit.eswincomputing.com:29418/tools/git-repo
repo sync -cdj4 --no-tags


#! /bin/bash
  ../qemu/bin/qemu-system-riscv64 -machine virt -m 256M -nographic \
 	-bios ../opensbi/build/platform/generic/firmware/fw_jump.bin \
 	-kernel ../linux/arch/riscv/boot/Image \
 	-drive file=../busybox/rootfs.img,format=raw,id=hd0 \
 	-device virtio-blk-device,drive=hd0 \
 	-append "root=/dev/vda rw console=ttyS0" -gdb tcp::9527


http://gerrit.eswincomputing.com/c/riscv/opensbi/+/27819
http://gerrit.eswincomputing.com/c/linaro-swg/linux/+/27823
http://gerrit.eswincomputing.com/c/OP-TEE/build/+/27828


#
# Use 'blkid' to print the universally unique identifier for a
# device; this may be used with UUID= as a more robust way to name devices
# that works even if disks are added and removed. See fstab(5).
#
# <file system> <mount point>   <type>  <options>       <dump>  <pass>
proc            /proc   proc    defaults    0   0
sysfs           /sys    sysfs   defaults    0   0
tmpfs           /var    tmpfs   defaults    0   0
tmpfs           /tmp    tmpfs   defaults    0   0
tmpfs           /dev    tmpfs   defaults    0   0

	
	
#!/bin/sh
PATH=/sbin:/bin:/usr/sbin:/usr/bin
runlevel=S
prevlevel=N
umask 022
export PATH runlevel prevlevel
mount -a
mdev -s
	
