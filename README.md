If writing the firmware package to Package Resource has completed, or, if the device has downloaded the firmware package from the Package URI the state changes to Downloaded.
Writing an empty string to Package URI Resource or setting the Package Resource to NULL (‘\0’), resets the Firmware Update State Machine: the State Resource value is set to Idle and the Update Result Resource value is set to 0.
When in Downloaded state, and the executable Resource Update is triggered, the state changes to Updating.
If the Update Resource failed, the state returns at Downloaded.
If performing the Update Resource was successful, the state changes from Updating to Idle. 
The firmware update state machine is illustrated in Figure 29 of the LwM2M version 1.0 specification (and also in Figure E.6.1-1 of this specification). 

http://confluence.eswincomputing.com/pages/viewpage.action?pageId=57706561

git clone ssh://zhusonghe@gerrit.eswincomputing.com:29418/eswin/toolchain/daily -b e510-gcc

apt-get install libpython2.7
sudo apt-get install libatlas3-base

https://launchpadlibrarian.net/590354609/indicator-stickynotes-1.0.1.tar.gz

下载：https://github.com/umangv/indicator-stickynotes

PPA源安装：

sudo add-apt-repository ppa:umang/indicator-stickynotes

sudo apt update

sudo apt install indicator-stickynotes -y

jgk@E0004941:~/Desktop/FS0111/fota_saas/9500/test/package_restore$ md5sum output/*
diff
d028011e980db34c9a65cbf96c774734  output/kernel.bin
c476e7d49635d5ad5b332ce17bc8e2e7  output/uboot.bin
full
d028011e980db34c9a65cbf96c774734  output/kernel.bin
c476e7d49635d5ad5b332ce17bc8e2e7  output/uboot.bin


jgk@E0004941:~/Desktop/FS0111/fota_saas/9500/test/package_restore$ md5sum /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/*/*/*
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/1.0.1/A/ecm9500_0x7000_kernel_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.0.1/AC/ecm9500_kernel_0x7000_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.1.0/CA/ecm9500_kernel_0x7000_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.1.1.0/B/ecm9500_kernel_0x7000_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.1.1/C/ecm9500_cpu_a_0x7000_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.1/A/ecm9500_kernel_0x7000_18.1.8.bin
d028011e980db34c9a65cbf96c774734  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.1/A/ecm9500_kernel_0x7000_1.56.1.bin
d028011e980db34c9a65cbf96c774734  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.1/B/ecm9500_kernel_0x7000_1.56.1.bin
c476e7d49635d5ad5b332ce17bc8e2e7  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.1/B/ecm9500_uboot_0x1000_1.1.7.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.3/A/ecm9500_kernel_0x7000_18.1.8.bin
23bd26658787f7f4326aee45644fc645  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.3/A/ecm9500_uboot_0x1000_1.21.1.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.3/B/ecm9500_kernel_0x7000_18.1.8.bin
23bd26658787f7f4326aee45644fc645  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.3/B/ecm9500_uboot_0x1000_1.21.1.bin

d028011e980db34c9a65cbf96c774734  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.4/A/ecm9500_kernel_0x7000_1.56.1.bin
c476e7d49635d5ad5b332ce17bc8e2e7  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.4/A/ecm9500_uboot_0x1000_1.1.7.bin

d028011e980db34c9a65cbf96c774734  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.4/B/ecm9500_kernel_0x7000_1.56.1.bin
c476e7d49635d5ad5b332ce17bc8e2e7  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.4/B/ecm9500_uboot_0x1000_1.1.7.bin
23bd26658787f7f4326aee45644fc645  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.5/B/ecm9500_uboot_0x1000_1.21.1.bin
d028011e980db34c9a65cbf96c774734  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.6/B/ecm9500_kernel_0x7000_1.56.1.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.7/C/ecm9500_kernel_0x7000_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2.8/A/ecm9500_0x7000_kernel_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/12.2/A/ecm9500_kernel_0x7000_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/1.2.3/A/ecm9500_kernel_0x7000_18.1.8.bin
23bd26658787f7f4326aee45644fc645  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/1.2.3/A/ecm9500_uboot_0x1000_1.21.1.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/1.a.1/A/ecm9500_kernel_0x7000_18.1.8.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/2.1.1/A/ecm9500_uboot_0x1000_18.1.8.bin
c476e7d49635d5ad5b332ce17bc8e2e7  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/2.1.2/A/ecm9500_uboot_0x1000_1.1.7.bin
bbbcdc41fd892bdbf4af3ef315dd3383  /home/jgk/Desktop/FS0111/fota_saas/9500/test/package_make/test_data/2.1.3/A/ecm9500_uboot_0x1000_18.1.8.bin
jgk@E0004941:~/Desktop/FS0111/fota_saas/9500/test/package_restore$ 

fota_sign
	在src目录下执行make
local_upgrade
	在win10使用Qt Creator工具打开，直接编译运行
fota_agent
	在build目录下依次执行
	cmake ../client
	make

fota_sign
	在src目录下执行make, 会在当前目录生成signing.o和signing.a，其中signing.a是目标文件。
local_upgrade
	在win10使用Qt Creator工具（WIN10, Qt 5.9.1, Qt Creator 4.3.1, MinGW 5.3.0 32bit）打开，直接编译运行，会编译生成并打开本地升级工具；
	PS：如果按照build.bat的规定安装了开发工具，可直接双击build.bat打开本地升级工具。
