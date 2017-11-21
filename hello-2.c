#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>  // Needed for the module_init/exit

/*
 * Note __init __initdata will be freed while being builtin-module
 * after module is up.
 * __exit will not be built into builtin-modules.
 */

static int hello_data __initdata = 2;

static int __init hello_2_init(void)
{
	/*
	 * This info can only be viewed in
	 * journalctl -kr
	 */
	printk(KERN_INFO "HELLO world %d.\n", hello_data);
	return 0;
}

static void __exit hello_2_exit(void)
{
	/* This info will be displayed on tty */
	printk(KERN_ALERT "Goodbye world.\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);
