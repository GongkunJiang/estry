# /data/0523/linux/drivers/misc/misc_tee.c
```c
#include <linux/module.h> 
#include <linux/miscdevice.h> 
#include <linux/fs.h> 

static int misc_tee_open(struct inode *inode, struct file *f)
{
    pr_info("misc_tee_open() is called.\n"); 
    return 0;
}

static int misc_tee_close(struct inode *inode, struct file *f)
{
    pr_info("misc_tee_close() is called.\n");
    return 0;
}

static long misc_tee_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
    pr_info("misc_tee_ioctl() is called. cmd = %d, arg = %ld\n", cmd, arg); 
    return 0; 
}

static const struct file_operations misc_tee_fops = {
    .owner = THIS_MODULE, 
    .open = misc_tee_open, 
    .release = misc_tee_close, 
    .unlocked_ioctl = misc_tee_ioctl,
};

/* declare & initialize struct miscdevice */ 
static struct miscdevice tee_miscdevice= {
    .minor = MISC_DYNAMIC_MINOR, 
    .name ="misc_tee", 
    .fops = &misc_tee_fops,
}; 

static int __init tee_init(void)
{
    int ret_val; 
    pr_info("misc_tee init\n"); 

    /* Register the device with the kernel */
    ret_val = misc_register(&tee_miscdevice);

    if (ret_val != 0) {
        pr_err("could not register the misc device misc_tee"); 
        return ret_val; 
    }

    pr_info("misc_tee: got minor %d\n",tee_miscdevice.minor);
    return 0; 
}

static void __exit tee_exit(void)
{
    pr_info("misc_tee exit\n"); 
    /* unregister the device with the Kernel */ 
    misc_deregister(&tee_miscdevice); 
} 

module_init(tee_init); 
module_exit(tee_exit); 

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("JGK"); 
MODULE_DESCRIPTION("This is the minitee_char_driver using misc framework");
```

# /data/0523/linux/drivers/misc/Kconfig
```
config MISC_TEE
	tristate "MISC_TEE"
	default y
	help
		This is a simple miscellaneous device driver for tee.
```

# /data/0523/linux/drivers/misc/Makefile
```
obj-$(CONFIG_MISC_TEE)	+= misc_tee.o
```
