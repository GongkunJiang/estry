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
