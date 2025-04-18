#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/string.h>

#define DRIVER_NAME "click_driver"

static struct kobject *click_kobj;
static int value = 0; // Stores 0 or 1


static ssize_t value_show(struct kobject *kobj, 
                         struct kobj_attribute *attr, 
                         char *buf)
{
    return scnprintf(buf, PAGE_SIZE, "%d\n", value);
}


static ssize_t trigger_store(struct kobject *kobj, 
                            struct kobj_attribute *attr,
                            const char *buf, 
                            size_t count)
{
    int ret, new_val;

    ret = kstrtoint(buf, 10, &new_val);
    if (ret < 0)
        return ret;

    if (new_val == 1) {
        printk(KERN_INFO "clicked\n"); // Log to dmesg
        value = 0; // Reset to 0
    } else {
        value = new_val;
    }

    return count;
}


static struct kobj_attribute value_attr = __ATTR_RO(value);
static struct kobj_attribute trigger_attr = __ATTR(trigger, 0660, NULL, trigger_store);

static struct attribute *click_attrs[] = {
    &value_attr.attr,
    &trigger_attr.attr,
    NULL,
};

static struct attribute_group click_attr_group = {
    .attrs = click_attrs,
};

static int __init click_driver_init(void)
{
    int ret;

   
    click_kobj = kobject_create_and_add("click", kernel_kobj);
    if (!click_kobj)
        return -ENOMEM;

    
    ret = sysfs_create_group(click_kobj, &click_attr_group);
    if (ret) {
        kobject_put(click_kobj);
        return ret;
    }

    pr_info("%s initialized\n", DRIVER_NAME);
    return 0;
}

static void __exit click_driver_exit(void)
{
    kobject_put(click_kobj);
    pr_info("%s exited\n", DRIVER_NAME);
}

module_init(click_driver_init);
module_exit(click_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YourName");
MODULE_DESCRIPTION("Sysfs Click Driver");
