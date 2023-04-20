./key_app mode=private filename=/home/jgk/Desktop/FS0117/fota_saas/9500/fota_agent/sample/cprik.der
Q(X): 474109989604E08CB026F649DCE17947244DC3F2E65D3BEA91EC7784588F9D18
Q(Y): 0F957D5A8E267541F32D7CF34684D15AB1564555EF389C411A3616D1333E4D97
Q(Z): 01
D   : 4D3A30E754A73C48349A1EE9B38109AF4CFC01D47C3A96FE6DCCA028AD85F3BD



${PATH_TO_OPEN_SBI}/build/platform/rv32imac/flash_boot_gen -f ${INPUT_FILE} -s 0x80000000 -o ${OUTPUT_FILE} -T ${PATH_TO_OPEN_SBI}/build/platform/link.ld -L${PATH_TO_OPEN_SBI}/build/platform/lib -lsbi

${PATH_TO_OPEN_SBI}/build/platform/lib/libsbi.a -Ttext=0x80000000 -o ${OUTPUT_FILE}
qemu-system-riscv64 -machine virt -bios ${PATH_TO_OPEN_SBI}/build/platform/fw_jump.elf -kernel ${PATH_TO_BINARY_FILE} -append "console=ttyS0" -nographic
make PLATFORM=<platform> CROSS_COMPILE=<cross-compiler-prefix> FW_PAYLOAD_PATH=<payload-file> LIBS_ONLY=y

=> ERROR [2/2] RUN apt-get update -q     && apt-get install -y --no-install-recommends         cowsay         sudo                                 61.1s
------                                                                                                                                                    
 > [2/2] RUN apt-get update -q     && apt-get install -y --no-install-recommends         cowsay         sudo:                                             
#0 30.80 Err:1 http://deb.debian.org/debian bullseye InRelease                                                                                            
#0 30.80   Could not connect to debian.map.fastlydns.net:80 (146.75.114.132), connection timed out Unable to connect to deb.debian.org:http:              
#0 30.80 Err:2 http://deb.debian.org/debian bullseye-updates InRelease                                                                                    
#0 30.80   Unable to connect to deb.debian.org:http:                                                                                                      
#0 31.05 Get:3 http://security.debian.org/debian-security bullseye-security InRelease [48.4 kB]
#0 61.08 Err:3 http://security.debian.org/debian-security bullseye-security InRelease
#0 61.08   Connection timed out [IP: 151.101.194.132 80]
#0 61.09 Reading package lists...
#0 61.10 W: Failed to fetch http://deb.debian.org/debian/dists/bullseye/InRelease  Could not connect to debian.map.fastlydns.net:80 (146.75.114.132), connection timed out Unable to connect to deb.debian.org:http:
#0 61.10 W: Failed to fetch http://security.debian.org/debian-security/dists/bullseye-security/InRelease  Connection timed out [IP: 151.101.194.132 80]
#0 61.10 W: Failed to fetch http://deb.debian.org/debian/dists/bullseye-updates/InRelease  Unable to connect to deb.debian.org:http:
#0 61.10 W: Some index files failed to download. They have been ignored, or old ones used instead.
#0 61.10 Reading package lists...
#0 61.11 Building dependency tree...
#0 61.11 Reading state information...
#0 61.11 E: Unable to locate package cowsay
#0 61.11 E: Unable to locate package sudo
------
extras.Dockerfile:19
--------------------
  18 |     # hadolint ignore=DL3008,DL3009
  19 | >>> RUN apt-get update -q \
  20 | >>>     && apt-get install -y --no-install-recommends \
  21 | >>>         # Add more dependencies here
  22 | >>>         cowsay \
  23 | >>>         sudo
  24 |     
--------------------
ERROR: failed to solve: process "/bin/sh -c apt-get update -q     && apt-get install -y --no-install-recommends         cowsay         sudo" did not complete successfully: exit code: 100
make: *** [Makefile:174: build_user] Error 1


jgk@E0004941:/data/a710/build$ file sel4test_build/elfloader/elfloader 
sel4test_build/elfloader/elfloader: ELF 64-bit LSB executable, UCB RISC-V, RVC, soft-float ABI, version 1 (SYSV), statically linked, with debug_info, not stripped
Submodule 'dejagnu' (https://git.savannah.gnu.org/git/dejagnu.git) registered for path 'dejagnu'



Submodule 'musl' (https://git.musl-libc.org/git/musl) registered for path 'musl'





https://isabelle.sketis.net/components/gnu-utils-20211030.tar.gz
https://github.com/seL4/l4v/blob/master/docs/setup.md
# 拉取a710项目并打开
mkdir a710
cd a710
repo init -u ssh://jianggongkun@gerrit.eswincomputing.com:29418/platform/manifest -b a710-tee --repo-url=ssh://jianggongkun@gerrit.eswincomputing.com:29418/tools/git-repo
repo sync -cdj4 --no-tags
repo forall -c git lfs pull
# 切换repo版本
## 切换为google开源版
cd ~/bin/
cp repo.googke_new repo
## 将a710的.repo目录临时屏蔽
cd -
mv .repo .repo_bk
# 拉取seL4test项目
mkdir seL4test
cd seL4test
repo init -u https://github.com/seL4/sel4test-manifest.git
repo sync
# 添加编译脚本
## 在script目录下新增脚本make_seL4test.sh文件
#! /bin/bash
DIR=../build/sel4test_build
if [ -d $DIR ];then
    rm -rf $DIR
fi
mkdir $DIR
cd $DIR
../../seL4test/init-build.sh -DSIMULATION=TRUE -DRISCV64=1 -DPLATFORM=qemu-riscv-virt -DCROSS_COMPILER_PREFIX=`pwd`/../../toolchain/bin/riscv64-unknown-elf- 
ninja 
../../toolchain/bin/riscv64-unknown-elf-objcopy -O binary elfloader/elfloader ../elfloader.bin
## 设为可执行文件
chmod +x make_seL4test.sh
## 同步到make_all.sh中编译tee前的位置
echo "===== Build seL4test ====="
./make_seL4test.sh
# 修改运行脚本run.sh和调试脚本gdb-dbg.sh
-device loader,file=elfloader.bin,addr=0x81200000 
# 添加jgk-dbg.sh
#!/bin/bash
../toolchain/bin/riscv-unknown-linux-gnu-gdb \
-iex "file debug/fw.elf" \
-iex "target remote :12345" \
-iex "add-symbol-file sel4test_build/kernel/kernel.elf" \
-iex "add-symbol-file sel4test_build/apps/sel4test-driver/sel4test-driver" \
-iex "add-symbol-file sel4test_build/elfloader/elfloader -o 0x7e000" \
-iex "add-symbol-file debug/u-boot -o 0x1ffeaa000" \
-iex "add-symbol-file debug/vmlinux"
## 设为可执行文件
chmod +x jgk-dbg.sh
# 添加相关定义
## opensbi/platform/eswin/a710/config.mk
CFG_SEL4_SUPPORT=y
SEL4_LOAD_ADDR=0xffffffff84000000
ELF_LOAD_ADDR=0x81200000
## opensbi/lib/sbi/objects.mk
libsbi-objs-y += sbi_ecall_sel4.o
platform-cflags-$(CFG_TEE_SUPPORT) += -DSEL4_SUPPORT
## opensbi/lib/sbi/sbi_init.c
#include <sbi_utils/sel4/sel4_sm_dispatcher.h>
...
#ifdef SEL4_SUPPORT
	sel4_os_init();
#endif
## seL4test/kernel/src/arch/riscv/head.S
#define SEL4_SBI_EXT_ECALL     (0x544546) 
#define SBI_EXT_SEL4_SECURE_FLAG				(0x53454355)
#define ECALL_TYPE_FAST     (1)
#define FUNCID_TYPE_SHIFT   (31)
#define ECALL_32            (0)
#define FUNCID_CC_SHIFT     (30)
#define FUNCID_OEN_SHIFT    (24)
#define FUNCID_NUM_MASK      (0xffff)
#define SEL4ECALL_SEL4D_RV(func_num) \
        ((ECALL_TYPE_FAST << FUNCID_TYPE_SHIFT) | \
         ((ECALL_32) << FUNCID_CC_SHIFT) | \
         (62 << FUNCID_OEN_SHIFT) | \
         ((func_num) & FUNCID_NUM_MASK))
#define SEL4ECALL_SEL4D_FUNCID_RETURN_ENTRY_DONE		0
#define SEL4ECALL_SEL4D_RETURN_ENTRY_DONE \
	SEL4ECALL_SEL4D_RV(SEL4ECALL_SEL4D_FUNCID_RETURN_ENTRY_DONE)
...
  //la ra, restore_user_context
  //jr ra
  li  t1, SBI_EXT_SEL4_SECURE_FLAG
  li  a0, SEL4ECALL_SEL4D_RETURN_ENTRY_DONE
  li  a7, SEL4_SBI_EXT_ECALL
  ecall
## opensbi/include/sbi/sbi_ecall_interface.h
#define SBI_EXT_SEL4				0x544546
## opensbi/include/sbi/sbi_ecall.h
extern struct sbi_ecall_extension ecall_sel4;
## opensbi/lib/sbi/sbi_ecall.c
#ifdef SEL4_SUPPORT
	ret = sbi_ecall_register_extension(&ecall_sel4);
	if (ret)
		return ret;
#endif
# 仿照TEE新增SEL4相关文件
## opensbi/lib/sbi/sbi_ecall_sel4.c
#include <sbi/sbi_ecall.h>
#include <sbi/sbi_ecall_interface.h>
#include <sbi_utils/sel4/sel4_sm_dispatcher.h>

struct sbi_ecall_extension ecall_sel4 = {
	.extid_start = SBI_EXT_SEL4,
	.extid_end = SBI_EXT_SEL4,
	.handle = sbi_ecall_sel4_handler,
};
## opensbi/include/sbi_utils/sel4
cp -rf /home/jgk/Desktop/riscv/opensbi/include/sbi_utils/sel4 opensbi/include/sbi_utils/sel4
## opensbi/lib/utils/sel4
cp -rf /home/jgk/Desktop/riscv/opensbi/lib/utils/sel4 opensbi/lib/utils/sel4
# 修改readl和writel
## seL4test/kernel/include/drivers/irq/riscv_plic0.h
static inline uint32_t readl(word_t addr)
{
    return *((volatile uint32_t *)(addr - 0x10000000));
    // return *((volatile uint32_t *)(addr));
}
static inline void writel(uint32_t val, word_t addr)
{
    *((volatile uint32_t *)(addr - 0x10000000)) = val;
    // *((volatile uint32_t *)(addr)) = val;
}
# build
## build/Makefile
	rm -rf sel4test_build && rm kernel.bin && rm sel4test-driver.bin && rm elfloader.bin && rm image.bin
## 编译
cd build
make
make all
# 运行
./run.sh
