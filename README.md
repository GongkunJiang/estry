I had to do it on Linux Mint as I could not find a solution for windows. The modified answer is below.

# Install compiler and tools
$ sudo apt-get install build-essential libtool python-dev

# Install cmake
$ sudo apt-get install cmake

$ wget https://github.com/libarchive/libarchive/releases/download/v3.4.1/libarchive-3.4.1.tar.xz
$ tar -xJf libarchive-3.4.1.tar.xz

# Configure using cmake...
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=/usr/local ../libarchive-3.4.1

# Now compile and install...
$ make
$ sudo make install

$ sudo sh -c 'echo /usr/local/lib > /etc/ld.so.conf.d/libarchive3.conf'
$ sudo ldconfig

$pip install python-libarchive


https://docs.sel4.systems/projects/sel4-tutorials/debugging-guide
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


Running seL4
This section presents a case study, by the end of which you can run seL4test on a simulator.

Fetching, Configuring and Building seL4test
To build a project, you need to:

check out the sources using Repo,
configure a target build using CMake,
build the project using Ninja.
Use repo to check sel4test out from GitHub. Its manifest is located in the sel4test-manifest repository.
mkdir seL4test
cd seL4test
repo init -u https://github.com/seL4/sel4test-manifest.git
repo sync
Configure an x86_64 build directory, with a simulation target to be run by Qemu. QEMU is a generic and open source machine emulator and virtualizer, and can emulate different architectures on different systems.
mkdir build-x86
cd build-x86
../init-build.sh -DPLATFORM=x86_64 -DSIMULATION=TRUE
ninja
The target configurations available for each project are potentially different depending on what the project supports. Building/Using describes how projects can generally be configured.

The build images are available in build-x86/images, and a script build-x86/simulation that will run Qemu with the correct arguments to run seL4test.
./simulate
On success, you should see:

Test VSPACE0002 passed

        </testcase>

        <testcase classname="sel4test" name="Test all tests ran">

        </testcase>

</testsuite>

All is well in the universe
For more information on seL4test see its project page.
