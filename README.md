repo init -u ssh://Gerrit账户@gerrit.eswincomputing.com:29418/e315s/manifest -b 分支名 --repo-url=ssh://Gerrit账户@gerrit.eswincomputing.com:29418/tools/git-repo

repo sync -cdj4 --no-tags
repo forall -c git lfs pull

分支名可用e315s-d_sf，e315s-d_sme，e315s-d_saas 任一替换。

PubkeyAcceptedKeyTypes=+ssh-rsa

wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/sublimehq-archive.gpg
echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
sudo apt-get update
sudo apt-get install sublime-text
sudo apt-get install apt-transport-https

VBoxGuestAdditions_6.1.38.iso
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

https://github.com/llvm/llvm-project/releases/

https://github.com/buildroot/buildroot/archive/2019.02.2/buildroot-2019.02.2.tar.gz
https://marketplace.visualstudio.com/search?target=VSCode&category=All%20categories&sortBy=Installs
https://marketplace.visualstudio.com/_apis/public/gallery/publishers/ms-vscode/vsextensions/cpptools/1.13.3/vspackage?targetPlatform=linux-arm64
https://marketplace.visualstudio.com/_apis/public/gallery/publishers/ms-vscode/vsextensions/cpptools/1.13.3/vspackage?targetPlatform=linux-x64
https://packages.emqx.net/MQTTX/v1.8.3/MQTTX_1.8.3_amd64.snap
	https://repo.almalinux.org/almalinux/9/BaseOS/aarch64/os/Packages/glibc-2.34-28.el9_0.2.aarch64.rpm
https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/snapshot/linux-6.1-rc4.tar.gz
# server
## 检测版本号
read 0 /3/0/3
## Read设备状态信息
read 0 /5/0/3
### 设备电池电量
read 0 /3/0/9
### 设备剩余空间
read 0 /3/0/10
### 无限信号强度
read 0 /4/0/2
### cell ID
read 0 /4/0/8
## 订阅升级状态
observe 0 /5/0/3
## 推送升级包地址 没有地方存
write 0 /5/0/1 eswin.com
## 执行升级
exec 0 /5/0/2
## 取消订阅升级状态
cancel 0 /5/0/3

# client
## 上报下载中 
notify Downloading
## pull升级包
pull url
## 上报下载完成
notify Downloaded
## 上报执行升级中
notify Updating
## 上报升级结果
notify Idle

# 设备状态
0: Idle (before downloading or after successful updating) 
1: Downloading (The data sequence is on the way) 
2: Downloaded 
3: Updating

# 升级结果
0: Initial value. 
1: Firmware updated successfully. 
2: Not enough flash memory for the new firmware package. 
3: Out of RAM during downloading process. 
4: Connection lost during downloading process. 
5: Integrity check failure for new downloaded package. 
6: Unsupported package type. 
7: Invalid URI.
8: Firmware update failed. 
9: Unsupported protocol.

sudo apt update
# python python-crypto
sudo apt install android-tools-adb android-tools-fastboot autoconf \
        automake bc bison build-essential cscope curl device-tree-compiler \
        expect flex ftp-upload gdisk iasl libattr1-dev libc6:i386 libcap-dev \
        libftdi-dev libglib2.0-dev libhidapi-dev libncurses5-dev \
        libpixman-1-dev libssl-dev libstdc++6:i386 libtool libz1:i386 make \
        mtools netcat unzip uuid-dev \
        xdg-utils xterm xz-utils zlib1g-dev git libdivsufsort-dev libbz2-dev

sudo tar -xvf gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar -C /opt/
sudo tar -xvf gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf.tar -C /opt/
sudo vim ~/.bashrc
PATH=$PATH:/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin
PATH=$PATH:/opt/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin
source ~/.bashrc


dl
├── arm-trusted-firmware
│   └── arm-trusted-firmware-xilinx-v2018.2.tar.gz
├── buildroot
│   └── buildroot-2019.02.2.tar.gz
├── cJSON
│   └── cJSON-v1.7.7.tar.gz
├── entropy_assess
│   └── entropy_assess-v1.0.tar.gz
├── linux
│   └── linux-xilinx-v2018.2.tar.gz
├── mbedtls
│   └── mbedtls-2.16.0-apache.tgz
├── openssl
│   └── openssl-1.1.1.tar.gz
├── optee_client
│   └── optee_client-3.5.0.tar.gz
├── optee_os
│   └── optee_os-3.5.0.tar.gz
├── paho_mqtt
│   └── paho_mqtt-v1.1.0.tar.gz
├── u-boot
│   └── u-boot-xilinx-v2018.2.tar.gz
└── wakaama
    └── wakaama-3e038d3abb8d398bba2373815a05308d41774aa1.tar.gz

./coding_format.sh /home/jgk/Desktop/JY1021/sw/applications/updateservice/host/core
./coding_format.sh /home/jgk/Desktop/JY1021/sw/applications/fota/host/core

cp .clang-format /home/jgk/Desktop/JY1021/sw/applications/fota/host/core
cp .clang-format /home/jgk/Desktop/JY1021/sw/applications/updateservice/host/core

./coding_format.sh /home/jgk/Desktop/JY1021/sw/applications/updateservice/host/core
./coding_format.sh /home/jgk/Desktop/JY1021/sw/applications/fota/host/core


sw/applications
├── fota
│	├── host
│	│   ├── core					# FOTA download agent client application scrambled code.
│	│   ├── inc						# FOTA download agent client application headers.
│	│   └── src						# FOTA download agent client application code.
│	│ 		├── creds				# MQTT client credentials.
│	│ 		├── paho_mqtt_embedded	# MQTT source code.
│	│ 		├── msg_client.c		# MQTT client's sample implementation.
│	│ 		└── port.c  			# FOTA download agent client application porting code.
│	└── ta 							# FOTA download agent trusted application.
└── updateservice
	├── creds 						# FOTA update agent credentials.
	├── host
	│   ├── core					# FOTA update agent client application scrambled code.
	│   ├── inc						# FOTA update agent client application headers.
	│   └── port					# FOTA update agent client application porting code.
	└── ta 							# FOTA update agent trusted application.

git clone --recurse-submodules https://github.com/eclipse/wakaama.git



# Generate public key content
fotakey-header      := src/creds/generated/mqttkey.h
fotakey-bin         := src/creds/rsapubkey.pem
$(fotakey-header): $(fotakey-bin)
	$(call fcheck,bin2h,$<,mqtt_key,,"static const",,,)
