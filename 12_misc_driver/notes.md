Misc drivers
================

In UNIX, Linux and similar operating systems, every device is identified by two numbers: a “major” number and a “minor” number.

These numbers can be seen by invoking ls -l /dev.

Every device driver registers its major number with the kernel and is completely responsible for managing its minor numbers

Every driver needs to register a major number, even if it only deals with a single device.

Misc (or miscellaneous) drivers are simple char drivers that share certain common characteristics

The kernel abstracts these commonalities into an API (implemented in drivers/char/misc.c), and this simplifies the way these drivers are initialized.

All misc drivers are assigned a major number of 10, but each can choose a single minor number.

So, if you have  a char driver needs to support multiple devices, it's not the candidate for being a misc driver.

===================================================================================
Consider the sequence of initialization steps that a char driver performs:
============================================================================
1. Allocates major/minor number using alloc_chrdev_region() and friends
2. Creates /dev and /sys nodes using class_device_create() function
3. Register itself as a char driver using cdev_init() and cdev_add()

===================================
With misc driver
===================================

static struct miscdevice misc_dev ={
        .minor = 10,
    .name = MYDEV_NAME,
    .fops = &mycdrv_fops,
};

misc_register(&misc_dev);

In the above example, I have statically assigned a minor number 10. You can also request for dynamic minor number assignment by specifying MISC_DYNAMIC_MINOR in the minor field.

Each misc driver automatically appears under /sys/class/misc without explicit effort from the driver writer.

===============================
Conclusion
===============================

The misc API seems to make your life easier when you're writing a small character driver and do not want to need to allocate a new major number only to use one minor number, for example

It simplifies things, but all the file operations are still available using the fops member of struct miscdevice. The basic difference is you only get one minor number per misc device.



