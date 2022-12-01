sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget \
  python3-dev python3-pip python3-setuptools python3-tk python3-wheel xz-utils file \
  make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1

git clone https://github.com/zephyrproject-rtos/net-tools
cd net-tools
make

Setup DTLS security in Leshan Demo Server:

Open up the Leshan Demo Server web UI

Click on “Security”

Click on “Add new client security configuration”

Enter the following data:

Client endpoint: qemu_x86

Security mode: Pre-Shared Key

Identity: Client_identity

Key: 000102030405060708090a0b0c0d0e0f

Start the Zephyr sample
