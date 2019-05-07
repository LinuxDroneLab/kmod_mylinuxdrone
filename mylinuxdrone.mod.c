#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xc37b2c25, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x82b83c7d, __VMLINUX_SYMBOL_STR(bus_register) },
	{ 0xa1fbf4b8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x89c42ec, __VMLINUX_SYMBOL_STR(driver_register) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
	{ 0xb6484d4a, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0xed52cd0a, __VMLINUX_SYMBOL_STR(device_register) },
	{ 0xaf2c31c8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xe9df9a21, __VMLINUX_SYMBOL_STR(of_device_is_available) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xa0490bcd, __VMLINUX_SYMBOL_STR(driver_unregister) },
	{ 0x84b183ae, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x4778a619, __VMLINUX_SYMBOL_STR(bus_unregister) },
	{ 0xa440161a, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0x586ac50c, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xcdf20a7, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xf4e3c975, __VMLINUX_SYMBOL_STR(device_unregister) },
	{ 0xb6883d59, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x5be4cf28, __VMLINUX_SYMBOL_STR(dev_set_name) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

