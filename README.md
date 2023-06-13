repo init -u ssh://liushiwei@gerrit.eswincomputing.com:29418/platform/manifest -b a710-sdk-d_dev --repo-url=ssh://liushiwei@gerrit.eswincomputing.com:29418/tools/git-repo
repo sync -cdj4 --no-tags


#! /bin/bash
  ../qemu/bin/qemu-system-riscv64 -machine virt -m 256M -nographic \
 	-bios ../opensbi/build/platform/generic/firmware/fw_jump.bin \
 	-kernel ../linux/arch/riscv/boot/Image \
 	-drive file=../busybox/rootfs.img,format=raw,id=hd0 \
 	-device virtio-blk-device,drive=hd0 \
 	-append "root=/dev/vda rw console=ttyS0" -gdb tcp::9527


http://gerrit.eswincomputing.com/c/riscv/opensbi/+/27819
http://gerrit.eswincomputing.com/c/linaro-swg/linux/+/27823
http://gerrit.eswincomputing.com/c/OP-TEE/build/+/27828

/* SPDX-License-Identifier: BSD-2-Clause */
#ifdef RV32
OUTPUT_FORMAT("elf32-littleriscv")
OUTPUT_ARCH(riscv)
#endif
#ifdef RV64
OUTPUT_FORMAT("elf64-littleriscv")
OUTPUT_ARCH(riscv)
#endif

#ifndef CFG_FTRACE_BUF_SIZE
#define CFG_FTRACE_BUF_SIZE 2048
#endif

SECTIONS {
	.ta_head : {*(.ta_head)}
	.text : {
		__text_start = .;
		*(.text .text.*)
		*(.stub)
		*(.gnu.linkonce.t.*)
		__text_end = .;
	}
	.note.gnu.property : { *(.note.gnu.property) }
        .plt : { *(.plt) }

	.eh_frame_hdr : {
		*(.eh_frame_hdr)
		*(.eh_frame_entry .eh_frame_entry.*)
	}
	.eh_frame : { KEEP(*(.eh_frame)) *(.eh_frame.*) }
	.gcc_except_table : { *(.gcc_except_table .gcc_except_table.*) }
	.rodata : {
		*(.gnu.linkonce.r.*)
		*(.rodata .rodata.*)
	}
        .ctors : { *(.ctors) }
        .dtors : { *(.dtors) }
	.dynsym : { *(.dynsym) }
	.dynstr : { *(.dynstr) }
	.hash : { *(.hash) }

	/* Page align to allow dropping execute bit for RW data */
	. = ALIGN(4096);

	.dynamic : { *(.dynamic) }
	.tdata : { *(.tdata .tdata.* .gnu.linkonce.td.*) }
	.tbss : { *(.tbss .tbss.* .gnu.linkonce.tb.*) *(.tcommon) }
	.got : { *(.got.plt) *(.got) }
	.rel.text : { *(.rel.text) *(.rel.gnu.linkonce.t*) }
	.rela.text : { *(.rela.text) *(.rela.gnu.linkonce.t*) }
	.rel.data : { *(.rel.data) *(.rel.gnu.linkonce.d*) }
	.rela.data : { *(.rela.data) *(.rela.gnu.linkonce.d*) }
	.rel.tdata : { *(.rel.tdata .rel.tdata.* .rel.gnu.linkonce.td.*) }
	.rela.tdata : { *(.rela.tdata .rela.tdata.* .rela.gnu.linkonce.td.*) }
	.rel.tbss : { *(.rel.tbss .rel.tbss.* .rel.gnu.linkonce.tb.*) }
	.rela.tbss : { *(.rela.tbss .rela.tbss.* .rela.gnu.linkonce.tb.*) }
	.rel.rodata : { *(.rel.rodata) *(.rel.gnu.linkonce.r*) }
	.rela.rodata : { *(.rela.rodata) *(.rela.gnu.linkonce.r*) }
	.rel.dyn : { *(.rel.dyn) }
	.rel.got : { *(.rel.got) }
	.rela.got : { *(.rela.got) }
	.rel.ctors : { *(.rel.ctors) }
	.rela.ctors : { *(.rela.ctors) }
	.rel.dtors : { *(.rel.dtors) }
	.rela.dtors : { *(.rela.dtors) }
	.rel.init : { *(.rel.init) }
	.rela.init : { *(.rela.init) }
	.rel.fini : { *(.rel.fini) }
	.rela.fini : { *(.rela.fini) }
	.rel.bss : { *(.rel.bss) }
	.rela.bss : { *(.rela.bss) }
	.rel.plt : { *(.rel.plt) }
	.rela.plt : { *(.rela.plt) }

	.data : { *(.data .data.* .gnu.linkonce.d.*) }
	.bss : {
		*(.bss .bss.* .gnu.linkonce.b.* COMMON)

		/*
		 * TA tracing using ftrace
		 * Reserve some space for the ftrace buffer, only if the
		 * TA is instrumented (i.e., some files were built with -pg).
		 */
		. = ALIGN(8);
		__ftrace_buf_start = .;
		. += DEFINED(MCOUNT_SYM) ?
			CFG_FTRACE_BUF_SIZE : 0;
		__ftrace_buf_end = .;
	}

	/DISCARD/ : { *(.interp) }
}





#
# Use 'blkid' to print the universally unique identifier for a
# device; this may be used with UUID= as a more robust way to name devices
# that works even if disks are added and removed. See fstab(5).
#
# <file system> <mount point>   <type>  <options>       <dump>  <pass>
proc            /proc   proc    defaults    0   0
sysfs           /sys    sysfs   defaults    0   0
tmpfs           /var    tmpfs   defaults    0   0
tmpfs           /tmp    tmpfs   defaults    0   0
tmpfs           /dev    tmpfs   defaults    0   0

	
	
#!/bin/sh
PATH=/sbin:/bin:/usr/sbin:/usr/bin
runlevel=S
prevlevel=N
umask 022
export PATH runlevel prevlevel
mount -a
mdev -s
	
