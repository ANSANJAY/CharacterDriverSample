#include <linux/module.h> /* for MODULE_* */
#include <linux/printk.h> /* for pr_info */

static int __init mod_init(void)
{
	if (request_module("crc7") > 0)
		pr_info("request_module failed to load\n");
	else
		pr_info("request_module loaded successfully\n");
	return 0;
}

static void __exit mod_exit(void)
{
}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("GPL");
