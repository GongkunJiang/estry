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

