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
jgk@E0004941:~/Desktop/wakaama/build-wakaama/examples/client$ lwm2mclient
Trying to bind LWM2M Client to port 56830
[lwm2m_init:65] Entering
[lwm2m_configure:272] endpointName: "testlwm2mclient", msisdn: "", altPath: "", numObject: 9
LWM2M Client "testlwm2mclient" started on port 56830
> [lwm2m_step:381] timeoutP: 60
[lwm2m_step:386] State: STATE_INITIAL
[object_getServers:1040] Entering
[lwm2m_data_new:160] size: 1
[lwm2m_data_encode_bool:519] value: false
[lwm2m_data_decode_bool:529] Entering
[lwm2m_data_decode_bool:580] result: 1, value: false
[lwm2m_data_free:178] size: 1
[lwm2m_data_new:160] size: 1
[lwm2m_data_encode_int:289] value: 123
[lwm2m_data_decode_int:299] Entering
[lwm2m_data_decode_int:362] result: 1, value: 123
[lwm2m_data_new:160] size: 1
[lwm2m_data_encode_int:289] value: 123
[lwm2m_data_decode_int:299] Entering
[lwm2m_data_decode_int:362] result: 1, value: 123
[lwm2m_data_free:178] size: 1
[lwm2m_data_new:160] size: 2
[lwm2m_data_encode_int:289] value: 300
[lwm2m_data_encode_string:214] "U"
[lwm2m_data_decode_int:299] Entering
[lwm2m_data_decode_int:362] result: 1, value: 300
[lwm2m_data_free:178] size: 2
[lwm2m_data_free:178] size: 1
[registration_start:1028] State: STATE_REGISTER_REQUIRED
[lwm2m_data_new:160] size: 1
[lwm2m_data_free:178] size: 1
[lwm2m_data_new:160] size: 1
[lwm2m_data_free:178] size: 1
[observe_step:521] Entering
[registration_step:2054] State: STATE_REGISTERING
[object_getRegisterPayloadBufferLength:788] Entering
[object_getRegisterPayload:886] Entering
Opening connection to server at ::1:5683
[transaction_new:160] method: 2, altPath: "", mID: 38577, token_len: 4
[transaction_new:162] NULL
[transaction_new:242] Exiting on success. new transac=0x560d08da13d0
[transaction_send:373] Entering: transaction=0x560d08da13d0
Sending 195 bytes to [::1]:5683
44 02 96 B1  B1 96 D4 FD  B2 72 64 11  28 39 6C 77   D........rd.(9lw
6D 32 6D 3D  31 2E 31 0D  05 65 70 3D  74 65 73 74   m2m=1.1..ep=test
6C 77 6D 32  6D 63 6C 69  65 6E 74 03  62 3D 55 06   lwm2mclient.b=U.
6C 74 3D 33  30 30 FF 3C  2F 3E 3B 72  74 3D 22 6F   lt=300.</>;rt="o
6D 61 2E 6C  77 6D 32 6D  22 3B 63 74  3D 31 31 30   ma.lwm2m";ct=110
2C 3C 2F 31  3E 3B 76 65  72 3D 31 2E  31 2C 3C 2F   ,</1>;ver=1.1,</
31 2F 30 3E  2C 3C 2F 32  2F 30 3E 2C  3C 2F 33 2F   1/0>,</2/0>,</3/
30 3E 2C 3C  2F 34 2F 30  3E 2C 3C 2F  35 2F 30 3E   0>,</4/0>,</5/0>
2C 3C 2F 36  2F 30 3E 2C  3C 2F 37 2F  30 3E 2C 3C   ,</6/0>,</7/0>,<
2F 33 31 30  32 34 3E 3B  76 65 72 3D  31 2E 30 2C   /31024>;ver=1.0,
3C 2F 33 31  30 32 34 2F  31 30 3E 2C  3C 2F 33 31   </31024/10>,</31
30 32 34 2F  31 31 3E 2C  3C 2F 33 31  30 32 34 2F   024/11>,</31024/
31 32 3E                                             12>
[transaction_step:460] Entering
[lwm2m_step:488] Final timeoutP: 2
[lwm2m_step:490] Final state: STATE_REGISTERING
 -> State: STATE_REGISTERING
13 bytes received from [::1]:5683
64 41 96 B1  B1 96 D4 FD  82 72 64 01  30  dA.......rd.0
[lwm2m_handle_packet:485] Entering
[lwm2m_handle_packet:492] Parsed: ver 1, type 2, tkl 4, code 2.01, mid 38577, Content type: 0
[lwm2m_handle_packet:494] Payload: 
[transaction_handleResponse:296] Entering
[prv_handleRegistrationReply:670] 123 Registration successful
[lwm2m_data_new:160] size: 1
[lwm2m_data_free:178] size: 1
[transaction_remove:282] Entering. transaction=0x560d08da13d0
[transaction_free:258] Entering. transaction=0x560d08da13d0
[lwm2m_step:381] timeoutP: 60
[lwm2m_step:386] State: STATE_REGISTERING
[registration_getStatus:1094] State: STATE_REGISTERING
[registration_getStatus:1101] 123 status: STATE_REGISTERED
[registration_getStatus:1125] reg_status: STATE_REGISTERED
[observe_step:521] Entering
[registration_step:2054] State: STATE_READY
[transaction_step:460] Entering
[lwm2m_step:488] Final timeoutP: 60
[lwm2m_step:490] Final state: STATE_READY
 -> State: STATE_READY
quit

[lwm2m_close:184] Entering
[lwm2m_deregister:83] Entering
[registration_deregister:1157] State: STATE_READY, 123 status: STATE_REGISTERED
[transaction_new:160] method: 4, altPath: "", mID: 38578, token_len: 4
[transaction_new:162] NULL
[transaction_new:242] Exiting on success. new transac=0x560d08da13d0
[transaction_send:373] Entering: transaction=0x560d08da13d0
Sending 13 bytes to [::1]:5683
44 04 96 B2  B2 96 EC FD  B2 72 64 01  30  D........rd.0
[transaction_free:258] Entering. transaction=0x560d08da13d0
jgk@E0004941:~/Desktop/wakaama/build-wakaama/examples/client$ 


# Generate public key content
fotakey-header      := src/creds/generated/mqttkey.h
fotakey-bin         := src/creds/rsapubkey.pem
$(fotakey-header): $(fotakey-bin)
	$(call fcheck,bin2h,$<,mqtt_key,,"static const",,,)

fotakey-header      := ./inc/generated/fotakey.h
fotakey-bin         := ./../creds/fotapubkey.pem
$(fotakey-header): $(fotakey-bin)
	$(call fcheck,bin2h,$<,fotapubkey,,"static const",,,)

target_compile_definitions(${target} PRIVATE LWM2M_WITH_LOGS)


jgk@E0004941:~/Desktop/wakaama/build-wakaama/examples/client$ lwm2mclient
Trying to bind LWM2M Client to port 56830
[lwm2m_init:65] Entering
[lwm2m_configure:272] endpointName: "testlwm2mclient", msisdn: "", altPath: "", numObject: 9
LWM2M Client "testlwm2mclient" started on port 56830
> [lwm2m_step:381] timeoutP: 60
[lwm2m_step:386] State: STATE_INITIAL
[object_getServers:1040] Entering
[lwm2m_data_new:160] size: 1
[lwm2m_data_encode_bool:519] value: false
[lwm2m_data_decode_bool:529] Entering
[lwm2m_data_decode_bool:580] result: 1, value: false
[lwm2m_data_free:178] size: 1
[lwm2m_data_new:160] size: 1
[lwm2m_data_encode_int:289] value: 123
[lwm2m_data_decode_int:299] Entering
[lwm2m_data_decode_int:362] result: 1, value: 123
[lwm2m_data_new:160] size: 1
[lwm2m_data_encode_int:289] value: 123
[lwm2m_data_decode_int:299] Entering
[lwm2m_data_decode_int:362] result: 1, value: 123
[lwm2m_data_free:178] size: 1
[lwm2m_data_new:160] size: 2
[lwm2m_data_encode_int:289] value: 300
[lwm2m_data_encode_string:214] "U"
[lwm2m_data_decode_int:299] Entering
[lwm2m_data_decode_int:362] result: 1, value: 300
[lwm2m_data_free:178] size: 2
[lwm2m_data_free:178] size: 1
[registration_start:1028] State: STATE_REGISTER_REQUIRED
[lwm2m_data_new:160] size: 1
[lwm2m_data_free:178] size: 1
[lwm2m_data_new:160] size: 1
[lwm2m_data_free:178] size: 1
[observe_step:521] Entering
[registration_step:2054] State: STATE_REGISTERING
[object_getRegisterPayloadBufferLength:788] Entering
[object_getRegisterPayload:886] Entering
Opening connection to server at ::1:5683
[transaction_new:160] method: 2, altPath: "", mID: 38577, token_len: 4
[transaction_new:162] NULL
[transaction_new:242] Exiting on success. new transac=0x560d08da13d0
[transaction_send:373] Entering: transaction=0x560d08da13d0
Sending 195 bytes to [::1]:5683
44 02 96 B1  B1 96 D4 FD  B2 72 64 11  28 39 6C 77   D........rd.(9lw
6D 32 6D 3D  31 2E 31 0D  05 65 70 3D  74 65 73 74   m2m=1.1..ep=test
6C 77 6D 32  6D 63 6C 69  65 6E 74 03  62 3D 55 06   lwm2mclient.b=U.
6C 74 3D 33  30 30 FF 3C  2F 3E 3B 72  74 3D 22 6F   lt=300.</>;rt="o
6D 61 2E 6C  77 6D 32 6D  22 3B 63 74  3D 31 31 30   ma.lwm2m";ct=110
2C 3C 2F 31  3E 3B 76 65  72 3D 31 2E  31 2C 3C 2F   ,</1>;ver=1.1,</
31 2F 30 3E  2C 3C 2F 32  2F 30 3E 2C  3C 2F 33 2F   1/0>,</2/0>,</3/
30 3E 2C 3C  2F 34 2F 30  3E 2C 3C 2F  35 2F 30 3E   0>,</4/0>,</5/0>
2C 3C 2F 36  2F 30 3E 2C  3C 2F 37 2F  30 3E 2C 3C   ,</6/0>,</7/0>,<
2F 33 31 30  32 34 3E 3B  76 65 72 3D  31 2E 30 2C   /31024>;ver=1.0,
3C 2F 33 31  30 32 34 2F  31 30 3E 2C  3C 2F 33 31   </31024/10>,</31
30 32 34 2F  31 31 3E 2C  3C 2F 33 31  30 32 34 2F   024/11>,</31024/
31 32 3E                                             12>
[transaction_step:460] Entering
[lwm2m_step:488] Final timeoutP: 2
[lwm2m_step:490] Final state: STATE_REGISTERING
 -> State: STATE_REGISTERING
13 bytes received from [::1]:5683
64 41 96 B1  B1 96 D4 FD  82 72 64 01  30  dA.......rd.0
[lwm2m_handle_packet:485] Entering
[lwm2m_handle_packet:492] Parsed: ver 1, type 2, tkl 4, code 2.01, mid 38577, Content type: 0
[lwm2m_handle_packet:494] Payload: 
[transaction_handleResponse:296] Entering
[prv_handleRegistrationReply:670] 123 Registration successful
[lwm2m_data_new:160] size: 1
[lwm2m_data_free:178] size: 1
[transaction_remove:282] Entering. transaction=0x560d08da13d0
[transaction_free:258] Entering. transaction=0x560d08da13d0
[lwm2m_step:381] timeoutP: 60
[lwm2m_step:386] State: STATE_REGISTERING
[registration_getStatus:1094] State: STATE_REGISTERING
[registration_getStatus:1101] 123 status: STATE_REGISTERED
[registration_getStatus:1125] reg_status: STATE_REGISTERED
[observe_step:521] Entering
[registration_step:2054] State: STATE_READY
[transaction_step:460] Entering
[lwm2m_step:488] Final timeoutP: 60
[lwm2m_step:490] Final state: STATE_READY
 -> State: STATE_READY
quit

[lwm2m_close:184] Entering
[lwm2m_deregister:83] Entering
[registration_deregister:1157] State: STATE_READY, 123 status: STATE_REGISTERED
[transaction_new:160] method: 4, altPath: "", mID: 38578, token_len: 4
[transaction_new:162] NULL
[transaction_new:242] Exiting on success. new transac=0x560d08da13d0
[transaction_send:373] Entering: transaction=0x560d08da13d0
Sending 13 bytes to [::1]:5683
44 04 96 B2  B2 96 EC FD  B2 72 64 01  30  D........rd.0
[transaction_free:258] Entering. transaction=0x560d08da13d0
jgk@E0004941:~/Desktop/wakaama/build-wakaama/examples/client$ 

jgk@E0004941:~/Desktop/wakaama/build-wakaama/examples/server$ lwm2mserver 
[lwm2m_init:65] Entering
> [lwm2m_set_monitoring_callback:2039] Entering
[lwm2m_step:381] timeoutP: 60
[registration_step:2129] Entering
[transaction_step:460] Entering
[lwm2m_step:488] Final timeoutP: 60
195 bytes received from [::1]:56830
44 02 96 B1  B1 96 D4 FD  B2 72 64 11  28 39 6C 77   D........rd.(9lw
6D 32 6D 3D  31 2E 31 0D  05 65 70 3D  74 65 73 74   m2m=1.1..ep=test
6C 77 6D 32  6D 63 6C 69  65 6E 74 03  62 3D 55 06   lwm2mclient.b=U.
6C 74 3D 33  30 30 FF 3C  2F 3E 3B 72  74 3D 22 6F   lt=300.</>;rt="o
6D 61 2E 6C  77 6D 32 6D  22 3B 63 74  3D 31 31 30   ma.lwm2m";ct=110
2C 3C 2F 31  3E 3B 76 65  72 3D 31 2E  31 2C 3C 2F   ,</1>;ver=1.1,</
31 2F 30 3E  2C 3C 2F 32  2F 30 3E 2C  3C 2F 33 2F   1/0>,</2/0>,</3/
30 3E 2C 3C  2F 34 2F 30  3E 2C 3C 2F  35 2F 30 3E   0>,</4/0>,</5/0>
2C 3C 2F 36  2F 30 3E 2C  3C 2F 37 2F  30 3E 2C 3C   ,</6/0>,</7/0>,<
2F 33 31 30  32 34 3E 3B  76 65 72 3D  31 2E 30 2C   /31024>;ver=1.0,
3C 2F 33 31  30 32 34 2F  31 30 3E 2C  3C 2F 33 31   </31024/10>,</31
30 32 34 2F  31 31 3E 2C  3C 2F 33 31  30 32 34 2F   024/11>,</31024/
31 32 3E                                             12>
[lwm2m_handle_packet:485] Entering
[lwm2m_handle_packet:492] Parsed: ver 1, type 0, tkl 4, code 0.02, mid 38577, Content type: 40
[lwm2m_handle_packet:494] Payload: </>;rt="oma.lwm2m";ct=110,</1>;ver=1.1,</1/0>,</2/0>,</3/0>,</4/0>,</5/0>,</6/0>,</7/0>,</31024>;ver=1.0,</31024/10>,</31024/11>,</31024/12>
[handle_request:147] Entering
[uri_decode:103] altPath: ""
[registration_handleRequest:1773] /

New client #0 registered.
Client #0:
	name: "testlwm2mclient"
	version: "1.1"
	binding: "UDP"
	lifetime: 300 sec
	objects: /1 (1.1), /1/0, /2/0, /3/0, /4/0, /5/0, /6/0, /7/0, /31024 (1.0), /31024/10, /31024/11, /31024/12, 

> [message_send:870] Entering
[message_send:872] Size to allocate: 21
[message_send:879] coap_serialize_message() returned 13
Sending 13 bytes to [::1]:56830
64 41 96 B1  B1 96 D4 FD  82 72 64 01  30  dA.......rd.0
[lwm2m_step:381] timeoutP: 60
[registration_step:2129] Entering
[transaction_step:460] Entering
[lwm2m_step:488] Final timeoutP: 60
13 bytes received from [::1]:56830
44 04 96 B2  B2 96 EC FD  B2 72 64 01  30  D........rd.0
[lwm2m_handle_packet:485] Entering
[lwm2m_handle_packet:492] Parsed: ver 1, type 0, tkl 4, code 0.04, mid 38578, Content type: 0
[lwm2m_handle_packet:494] Payload: 
[handle_request:147] Entering
[uri_decode:103] altPath: ""
[registration_handleRequest:1773] /0

Client #0 unregistered.

> [registration_freeClient:1722] Entering
[message_send:870] Entering
[message_send:872] Size to allocate: 8
[message_send:879] coap_serialize_message() returned 8
Sending 8 bytes to [::1]:56830
64 42 96 B2  B2 96 EC FD   dB......
[lwm2m_step:381] timeoutP: 60
[registration_step:2129] Entering
[transaction_step:460] Entering
[lwm2m_step:488] Final timeoutP: 60
q


jgk@E0004941:~/Desktop/wakaama/build-wakaama/examples/server$ 

https://github.com/CanvasDM/lwm2m_firmware_update_module
