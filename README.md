Simulating with QEMU

In order to run seL4 projects on a simulator you will need QEMU:

sudo apt-get install qemu-system-arm qemu-system-x86 qemu-system-misc
Cross-compiling for ARM targets

To build for ARM targets you will need a cross compiler:

sudo apt-get install gcc-arm-linux-gnueabi g++-arm-linux-gnueabi
sudo apt-get install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu
(you can install the hardware floating point versions as well if you wish)

sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
Cross-compiling for RISC-V targets

To build for RISC-V targets you will need a cross compiler:

It is recommended to build the toolchain from source.

 git clone https://github.com/riscv/riscv-gnu-toolchain.git
 cd riscv-gnu-toolchain
 git submodule update --init --recursive
 export RISCV=/opt/riscv
 ./configure --prefix="${RISCV}" --enable-multilib
 make linux
After it is built, add the $RISCV/bin folder to your PATH. The built toolchain works for both 32-bit and 64-bit.

Alternatively, any pre-built toolchain with multilib enabled should work.
