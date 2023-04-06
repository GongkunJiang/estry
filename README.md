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
