/*
 * mld_pru_cntrl_channel.c
 *
 *  Created on: 07 mag 2019
 *      Author: andrea
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/init.h>
#include "mylinuxdrone.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Andrea Lambruschini <andrea.lambruschini@gmail.com>");

#define MLD_PRU_CNTRL_CHANNEL_NAME "mld-pru-control"
static int mld_pru_cntrl_channel_probe(struct mylinuxdrone_device *mlddev) {
    printk(KERN_ALERT "mld_pru_cntrl_channel_probe not implemented yet...\n");
    return 0;
}
static void mld_pru_cntrl_channel_remove(struct mylinuxdrone_device *mlddev) {
    printk(KERN_ALERT "mld_pru_cntrl_channel_remove not implemented yet...\n");
}
static void mld_pru_cntrl_channel_dev_release(struct device* dev) {
    struct mylinuxdrone_device *mlddev = to_mylinuxdrone_device(dev);
    printk(KERN_ALERT "mld_pru_cntrl_channel_dev_release dev:[%s] ...\n", mlddev->id.name);
    put_device(dev);
}
EXPORT_SYMBOL(mld_pru_cntrl_channel_dev_release);


static const struct of_device_id arm_mylinuxdrone_pru_control_matches[] = {
        { .compatible = "arm,mylinuxdrone_pru", .name = MLD_PRU_CNTRL_CHANNEL_NAME},
        {},
};
MODULE_DEVICE_TABLE(of, arm_mylinuxdrone_pru_control_matches);

static const struct mylinuxdrone_device_id arm_mylinuxdrone_pru_control_id[] = {
        { .name = MLD_PRU_CNTRL_CHANNEL_NAME },
        { },
};
MODULE_DEVICE_TABLE(mylinuxdrone, arm_mylinuxdrone_pru_control_id);

static struct mylinuxdrone_driver mld_pru_cntrl_channel_driver = {
        .probe = mld_pru_cntrl_channel_probe,
        .remove = mld_pru_cntrl_channel_remove,
        .id_table = arm_mylinuxdrone_pru_control_id,
        .driver = {
                .name = MLD_PRU_CNTRL_CHANNEL_NAME,
                .of_match_table = arm_mylinuxdrone_pru_control_matches,
                .owner = THIS_MODULE,
        },
};

static int __init mld_pru_cntrl_channel_init(void)
{
    int ret;
    struct mylinuxdrone_device* mydev;
    printk(KERN_ALERT "mld_pru_cntrl_channel_init...\n");

    ret = register_mylinuxdrone_driver(&mld_pru_cntrl_channel_driver);
    if(ret) {
        pr_err("failed to register mld_pru_cntrl_channel_driver: %d\n", ret);
        return ret;
    }
    printk(KERN_ALERT "mld_pru_cntrl_channel_driver registered ...\n");

    mydev = alloc_mylinuxdrone_device(MLD_PRU_CNTRL_CHANNEL_NAME, 0);
    if(!mydev) {
        pr_err("failed to create [%s] device: %d\n", MLD_PRU_CNTRL_CHANNEL_NAME, ret);
        return -ENOMEM;
    }
    mydev->dev.release = mld_pru_cntrl_channel_dev_release;
    ret = register_mylinuxdrone_device(mydev);
    if(ret) {
        pr_err("failed to register [%s] device on mylinuxdrone bus: %d\n", MLD_PRU_CNTRL_CHANNEL_NAME, ret);
        return ret;
    }
    printk(KERN_ALERT "mld_pru_cntrl_channel_init dev:[%s] registered\n", MLD_PRU_CNTRL_CHANNEL_NAME);
    printk(KERN_ALERT "mld_pru_cntrl_channel_init completed\n");
    return 0;
}

static void __exit mld_pru_cntrl_channel_fini(void)
{
    printk(KERN_WARNING "mld_pru_cntrl_channel_fini started ...\n");
    unregister_mylinuxdrone_driver(&mld_pru_cntrl_channel_driver);
    printk(KERN_WARNING "mld_pru_cntrl_channel_fini ...\n");
}

postcore_initcall(mld_pru_cntrl_channel_init);
module_exit(mld_pru_cntrl_channel_fini);
