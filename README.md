8da0eeae-f946-11ed-be56-0242ac120002
f7cbf0e0-c772-4eaa-9d18-0b5fecfebc53
712ae5ec-f557-11ed-a05b-0242ac120003
$ repo init -u https: //github.com/OP-TEE/manifest.git -m default.xml
There are two classes of clients, normal clients and supplicants. The latter is
a helper process for the TEE to access resources in Linux, for example file
system access. A normal client opens /dev/tee[0-9]* and a supplicant opens
/dev/teepriv[0-9].

Domain0 Region00          : 0x0000000002008000-0x000000000200bfff (I)
Domain0 Region01          : 0x0000000002000000-0x0000000002007fff (I)
Domain0 Region02          : 0x0000000080000000-0x000000008007ffff ()
Domain0 Region03          : 0x0000000000000000-0xffffffffffffffff (R,W,X)

init_coldboot(scratch, hartid) 在冷启动期间初始化OpenSBI
	sbi_scratch_init(scratch)	为每个有效的harid初始化scratch指针于hartid_to_scratch_table数组，并更新last_hartid_having_scratch为最后一个有效的hartid
	sbi_domain_init(scratch, hartid)	通过设置内存区域，引导hartid和可能分配的hart来初始化root domain
	sbi_scratch_alloc_offset(__SIZEOF_POINTER__)	在	scratch空间中分配一个偏移量用于存储一个指针(跟踪init_coldboot被调用的次数)
	sbi_hsm_init(scratch, hartid, TRUE) 初始化每个hart的状态数据
	sbi_platform_early_init(plat, TRUE) 为当前hart执行早期初始化, do nothing
	sbi_hart_init(scratch, TRUE) 检测hart特性(H)并为hart_features结构分配scratch内存，然后重新初始化hart
	sbi_console_init(scratch) 初始化SBI实现的控制台设备 
	sbi_pmu_init(scratch, TRUE) 初始化hart的性能监视器PMU
	sbi_boot_print_banner(scratch) 在控制台打印OpenSBI版本以及一个标语
	sbi_irqchip_init(scratch, TRUE) 初始化OpenSBI库中的中断控制器，如果设置了ext_irqfn，则启用机器外部中断
	sbi_ipi_init(scratch, TRUE) 初始化当前hart的IPI(进程间中断)并启用软件中断
	sbi_tlb_init(scratch, TRUE) 初始化TLB子系统，为TLB同步计数器、TLB FIFO队列和TLB FIFO内存分配内存(计数器为0,分配的内存初始化队列)。
	sbi_ipi_init(scratch, TRUE) 初始化计时器设备并将时间差设置为0
	sbi_ecall_init() 用结构体sbi_ecall_extension注册ecall扩展
	sbi_domain_finalize(scratch, hartid) 初始化和填充平台的域(next_addr、next_mode和next_arg1(设置为设备树blob的地址))
	sbi_hart_pmp_configure(scratch) 配置当前hart的PMP(物理内存保护)，遍历当前区域的内存区域并设置PMP标志
	sbi_platform_final_init(plat, TRUE)	用于当前hart的最终初始化
	sbi_boot_print_general(scratch) 打印各种平台、固件和SBI细节
	sbi_boot_print_domains(scratch)	打印系统中所有域的信息(名称、ID以及属于每个域的hart)
	sbi_boot_print_hart(scratch, hartid) 打印启动hart的详细信息
	wake_coldboot_harts(scratch, hartid) 唤醒所有等待冷启动完成的(其他)hart
	sbi_scratch_offset_ptr(scratch, init_count_offset) (*init_count)++ 记录boot(cold/warm)init的次数
	eswin_sme_init
	tee_os_domain_set
	tee_os_init
	ree_os_domain_set
	sbi_hsm_prepare_next_jump(scratch, hartid) 将hart的HSM状态由PENDING改为STARTED
	sbi_hart_switch_mode(hartid, scratch->next_arg1, scratch->next_addr, scratch->next_mode, FALSE) 切换hart模式到next_mode
