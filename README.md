
tmp/ccFojBcQ.o: in function `uart_putc':
/data/a510/tee/allinone/common/boot.c:49:(.text+0x88): relocation truncated to fit: R_RISCV_HI20 against `console_data'
collect2: error: ld returned 1 exit status
make: *** [Makefile:28: build/tee] Error 1

#include <stddef.h>

static struct uart_data console_data;

struct serial_chip {
	const struct serial_ops *ops;
};

struct serial_ops {
	void (*putc)(struct serial_chip *chip, int ch);
};
typedef unsigned long int paddr_t;
typedef unsigned long int vaddr_t;
typedef unsigned int        uint32_t;
struct io_pa_va {
	paddr_t pa;
	vaddr_t va;
};

struct uart_data {
    struct io_pa_va base;
    struct serial_chip chip;
};

#define container_of(ptr, type, member) \
	(__extension__({ \
		const typeof(((type *)0)->member) *__ptr = (ptr); \
		(type *)((unsigned long)(__ptr) - offsetof(type, member)); \
	}))

static vaddr_t chip_to_base(struct serial_chip *chip)
{
	struct uart_data *pd = container_of(chip, struct uart_data, chip);

	return pd->base.pa;
}

static inline void io_write32(vaddr_t addr, uint32_t val)
{
	*(volatile uint32_t *)addr = val;
}

static void uart_putc(struct serial_chip *chip, int ch)
{
	vaddr_t base = chip_to_base(chip);

	/* Write out character to transmit FIFO */
	io_write32(base, ch);
}

static const struct serial_ops uart_ops = {
	.putc = uart_putc,
};

void console_init(void)
{
	/* Init UART */
	console_data.base.pa = UART_BASE;
	console_data.chip.ops = &uart_ops;
	/* Register console */
	// register_serial_console(&console_data.chip);
}

int c_main(void)
{
	console_init();
	// EMSG("At phys mem hello\n");
	return 0;
}





/tmp/ccTDQwzM.o: in function `secure_monitor_init':
/data/a510/tee/e315s/tee/spe/arch/common/main.c:38:(.text+0x16): relocation truncated to fit: R_RISCV_HI20 against `.LC0'
/tmp/ccrnP0Gc.o: in function `trap_error':
/data/a510/tee/e315s/tee/spe/arch/common/trap.c:27:(.text+0x40): relocation truncated to fit: R_RISCV_HI20 against `__func__.0'
/tmp/ccsCld3Q.o: in function `eswin_getc':
/data/a510/tee/e315s/tee/spe/arch/common/console.c:28:(.text+0x8): relocation truncated to fit: R_RISCV_HI20 against `console_dev'
/tmp/ccfi3sUc.o: in function `ns16550_putc':
/data/a510/tee/e315s/tee/spe/drvs/e315s-ns16550.c:59:(.text+0x52): relocation truncated to fit: R_RISCV_HI20 against symbol `uart_base' defined in .sbss section in /tmp/ccfi3sUc.o
collect2: error: ld returned 1 exit status
make: *** [Makefile:66: /data/a510/tee/e315s/out/tee.elf] Error 1

http://gerrit.eswincomputing.com/c/eswin/tee/+/28083
http://gerrit.eswincomputing.com/c/linaro-swg/linux/+/27823
http://gerrit.eswincomputing.com/c/OP-TEE/build/+/27828
http://gerrit.eswincomputing.com/c/riscv/opensbi/+/27819


By including kern.ld.d in the Makefile, the build system ensures that any changes to the included header files will trigger a recompilation of kern.ld.S if necessary.
../../toolchain/riscv-linux-toolchain/bin/riscv64-unknown-linux-gnu-cpp -P -MT out/riscv-plat-eswin/core/kern.ld -MD -MF out/riscv-plat-eswin/core/.kern.ld.d \
        -nostdinc -isystem /data/0523/toolchain/riscv-linux-toolchain/bin/../lib/gcc/riscv64-unknown-linux-gnu/10.1.0/include -Ilib/libutils/isoc/include -Ilib/libutils/ext/include -Ilib/libmbedtls/include -Ilib/libmbedtls/mbedtls/include -Icore/lib/libtomcrypt/include -Icore/lib/libtomcrypt/src/headers -Icore/lib/libfdt/include -Ilib/libunw/include -Icore/arch/riscv/plat-eswin/. -Iout/riscv-plat-eswin/core -D__KERNEL__ -Icore/include -include out/riscv-plat-eswin/include/generated/conf.h -Iout/riscv-plat-eswin/core/include -Icore/arch/riscv/include -mcmodel=medany -march=rv64imafd -mabi=lp64d -Wno-missing-include-dirs -DRV64=1 -D__LP64__=1 -DTRACE_LEVEL=4 -DNDEBUG -Ildelf/include -Ilib/libutee/include core/arch/riscv/plat-eswin/kern.ld.S -o out/riscv-plat-eswin/core/kern.ld

#0  serial8250_uart_putc (chip=0x27c055568 <console_data+16>, ch=69) at core/drivers/serial8250_uart.c:37
#1  0x000000027c000840 in trace_ext_puts (str=str@entry=0x27c0a4660 <stack_tmp+1632> "E/TC:0 0 c_main:25 At phys mem hello\n")
    at core/arch/riscv/kernel/trace_ext.c:41
#2  0x000000027c040888 in trace_vprintf (function=function@entry=0x27c054e20 <__func__.1> "c_main", line=<optimized out>, level=<optimized out>, 
    level_ok=<optimized out>, fmt=fmt@entry=0x27c049020 "At phys mem hello\n", ap=ap@entry=0x27c0a47d8 <stack_tmp+2008>)
    at lib/libutils/ext/trace.c:176
#3  0x000000027c0408b4 in trace_printf (function=function@entry=0x27c054e20 <__func__.1> "c_main", line=line@entry=25, level=level@entry=1, 
    level_ok=level_ok@entry=true, fmt=fmt@entry=0x27c049020 "At phys mem hello\n") at lib/libutils/ext/trace.c:108
#4  0x000000027c0006d4 in c_main () at core/arch/riscv/kernel/boot.c:25
#5  0x000000027c00005c in _start () at core/arch/riscv/kernel/start.S:84




// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright 2022 NXP
 */

#include <assert.h>
#include <compiler.h>
#include <config.h>
#include <console.h>
#include <drivers/serial.h>
#include <kernel/spinlock.h>
#include <riscv.h>
#include <sbi.h>
#include <trace.h>
#include <util.h>

#ifdef CFG_RISCV_SBI_CONSOLE

struct sbi_console_data {
	struct serial_chip chip;
};

static struct sbi_console_data console_data __nex_bss;
static unsigned int sbi_console_global_lock __nex_bss = SPINLOCK_UNLOCK;

static void sbi_console_lock_global(void)
{
	cpu_spin_lock(&sbi_console_global_lock);
}

static void sbi_console_unlock_global(void)
{
	cpu_spin_unlock(&sbi_console_global_lock);
}

static void sbi_console_flush(struct serial_chip *chip __unused)
{
}

static void sbi_console_putc(struct serial_chip *chip __unused,
			     int ch)
{
	sbi_console_lock_global();
	sbi_console_putchar(ch);
	sbi_console_unlock_global();
}

static const struct serial_ops sbi_console_ops = {
	.flush = sbi_console_flush,
	.putc = sbi_console_putc,
};

static void sbi_console_init(struct sbi_console_data *pd)
{
	pd->chip.ops = &sbi_console_ops;
}

void console_init(void)
{
	sbi_console_init(&console_data);
	register_serial_console(&console_data.chip);
}

#endif /*CFG_RISCV_SBI_CONSOLE*/

