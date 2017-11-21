#include <linux/module.h>  // Needed by every module
#include <linux/kernel.h>  // Needed by macro KERN_INFO/ALERT

int init_module(void)
{
	/*
	 * This info can only be viewed in
	 * journalctl -kr
	 */
	printk(KERN_INFO "HELLO world.\n");
	return 0;
}

void cleanup_module(void)
{
	/* This info will be displayed on tty */
	printk(KERN_ALERT "Goodbye world.\n");
}
