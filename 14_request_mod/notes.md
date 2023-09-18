Loading Modules on Demand
=============================

Linux offers support for automatic loading and unloading of modules. This feature avoid wasting kernel memory by keeping drivers in core memory when not in use.

This ability to request additional modules when they are needed is particularly useful for drivers using module stacking.

To request the loading of a module, call request_module:

int request_module(const char *module_name);

Note that request_module is synchronous -- it will sleep until the attempt to load the module has completed. 

This means, of course, that request_module cannot be called from interrupt context.

The return value indicates that request_module was successful in running modprobe, but does not reflect the success status of modprobe itself

When the kernel code calls request_module, a new "kernel thread'' process is created, which runs modprobe in the user context.
