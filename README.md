3059301306072a8648ce3d020106082a8648ce3d03010703420004474109989604e08cb026f649dce17947244dc3f2e65d3bea91ec7784588f9d180f957d5a8e267541f32d7cf34684d15ab1564555ef389c411a3616d1333e4d97
此类指令用于从存储器（地址为 rs1 寄存器的值指定）中读出一个数据，存放至 rd 寄存
器中，并且将读出的数据与 rs2 寄存器的值进行计算，再将计算后的结果写回存储器（存储
器写回地址与读出地址相同）。

pip install -i https://pypi.tuna.tsinghua.edu.cn/simple some-package
pip install mypy -i http://pypi.douban.com/simple --trusted-host pypi.douban.com
west build -b qemu_x86 samples/hello_world
west build -t run

sudo apt install libpcap-dev

java -jar /home/jgk/Desktop/leshan/leshan-server-demo.jar -wp 8080
./tools/net-tools/loop-socat.sh
sudo ./tools/net-tools/loop-slip-tap.sh
cd zephyr
west build -b qemu_x86 samples/net/lwm2m_client
west build -t run

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
