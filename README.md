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
	
