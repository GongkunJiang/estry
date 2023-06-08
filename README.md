make ARCH=riscv defconfig arch/riscv/configs/defconfig
make -j 24 ARCH=riscv CROSS_COMPILE=/data/a510/toolchain/riscv-linux-toolchain/bin/riscv64-unknown-linux-gnu-

make PLATFORM=generic FW_PAYLOAD_PATH=../linux/arch/riscv/boot/Image CROSS_COMPILE=/data/a510/toolchain/riscv-linux-toolchain/bin/riscv64-unknown-linux-gnu-

qemu-system-riscv64 -M virt -m 256M -nographic \
	-bios build/platform/generic/firmware/fw_jump.bin \
	-kernel ../linux/arch/riscv/boot/Image \
	-drive file=/data/a510/build/out/rootfs.cpio.gz,format=raw,id=hd0 \
	-device virtio-blk-device,drive=hd0 \
	-append "root=/dev/vda rw console=ttyS0"


2023-06-06 15:53
Hi,
make ARCH=riscv defconfig KBUILD_DEFCONFIG=arch/riscv/configs/defconfig
新项目分支a510-minios基于a710-tee已创建。



下载：


#如果还未安装git lfs，则需要先安装该工具
sudo apt install git-lfs
 
repo init -u ssh://Gerrit账户@gerrit.eswincomputing.com:29418/platform/manifest -b a510-minios --repo-url=ssh://Gerrit账户@gerrit.eswincomputing.com:29418/tools/git-repo
repo sync -cdj4 --no-tags
repo forall -c git lfs pull
