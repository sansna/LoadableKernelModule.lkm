#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sansna");

static int myint = 100;
static char *mystr = "blah";
static int myarray[2] = {-1,1}; // This array can hold up to 2 ints.
static int arr_argc = 0;

module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myint, "An int");

module_param(mystr, charp, 0000);
MODULE_PARM_DESC(mystr, "An str");

module_param_array(myarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myarray, "An array of int");

static int __init hello_3_init(void)
{
	int i = 0;

	printk(KERN_INFO "Hello, world 3.\n");

	printk(KERN_INFO "myint is: %d\n", myint);

	printk(KERN_INFO "mystr is: %s\n", mystr);

	for (i = 0; i < arr_argc; i ++) {
		printk(KERN_INFO "myarray[%d] is %d\n", i, myarray[i]);
	}
	printk(KERN_INFO "A total of %d myarray ints\n", arr_argc);

	return 0;
}

static void __exit hello_3_exit(void)
{
	printk(KERN_INFO "Goodbye world 3.\n");
}

module_init(hello_3_init);
module_exit(hello_3_exit);
