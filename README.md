uint64_t translate(pte_t* page_table, uint64_t va) {
    uint64_t vpn[3];
    vpn[0] = (va >> 30) & 0x1    vpn[1] = (va >> 21) & 0x1ff;
    vpn[2] = (va >> 12) & 0x1ff;
    pte_t* pte = page_table;
    for (int i = 0; i < 3; i++) {
        uint64_t idx = vpn[i];
        if (!(pte[idx] & PTE_V)) {
            return 0;
        }
        pte = (pte_t*) (pte[idx] & ~0xfff);
    }
    return pte[va >> PAGE_SHIFT] & ~0xfff;
}
GSSXZEZ56G-eyJsaWNlbnNlSWQiOiJHU1NYWkVaNTZHIiwibGljZW5zZWVOYW1lIjoic2lnbnVwIHNjb290ZXIiLCJhc3NpZ25lZU5hbWUiOiIiLCJhc3NpZ25lZUVtYWlsIjoiIiwibGljZW5zZVJlc3RyaWN0aW9uIjoiIiwiY2hlY2tDb25jdXJyZW50VXNlIjpmYWxzZSwicHJvZHVjdHMiOlt7ImNvZGUiOiJQU0kiLCJmYWxsYmFja0RhdGUiOiIyMDI1LTA4LTAxIiwicGFpZFVwVG8iOiIyMDI1LTA4LTAxIiwiZXh0ZW5kZWQiOnRydWV9LHsiY29kZSI6IlBTVyIsImZhbGxiYWNrRGF0ZSI6IjIwMjUtMDgtMDEiLCJwYWlkVXBUb
https://download-cdn.jetbrains.com/cpp/CLion-2022.3.3.tar.gz
Spike
Building the GCC toolchain
It is recommended to build the toolchain from source.

 git clone https://github.com/riscv/riscv-gnu-toolchain.git
 cd riscv-gnu-toolchain
 git submodule update --init --recursive
 export RISCV=/opt/riscv
 ./configure --prefix="${RISCV}" --enable-multilib
 make linux
After it is built, add the $RISCV/bin folder to your PATH. The built toolchain works for both 32-bit and 64-bit.

Alternatively, any pre-built toolchain with multilib enabled should work.

Getting the Simulator
You can use either RISC-V ISA Simulator or QEMU >= v4.2 shipped with your Linux distribution.

If you prefer to build qemu from source, make sure you have the correct target enabled.

git clone https://git.qemu.org/git/qemu.git
cd qemu
mkdir build
cd build
../configure --prefix=/opt/riscv --target-list=riscv64-softmmu,riscv32-softmmu
make
Building seL4test
Checkout the sel4test project using repo as per seL4Test

repo init -u https://github.com/seL4/sel4test-manifest.git
repo sync
mkdir cbuild
cd cbuild
../init-build.sh -DPLATFORM=spike -DRISCV64=1
# The default cmake wrapper sets up a default configuration for the target platform.
# To change individual settings, run `ccmake` and change the configuration
# parameters to suit your needs.
ninja
# If your target binaries can be executed in an emulator/simulator, and if
# our build system happens to support that target emulator, then this script
# might work for you:
./simulate

If you plan to use the ./simulate script, please be sure to add the -DSIMULATION=1 argument when running cmake.

Generated binaries can be found in the images/ directory.

You can also use run the tests on the 32-bit spike platform by replacing the -DRISCV64=TRUE option with -DRISCV32=TRUE.
