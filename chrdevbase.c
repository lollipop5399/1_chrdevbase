#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>


#define CHRDEVBASE_MAJOR  200
#define CHRDEVBASE_NAME  "chrdevbase"

static char readbuf[100], writebuf[100];
static char kerneldata[] = {"kernel data!!!"};




static ssize_t chrdevbase_read(struct file *filp, __user char *buf, size_t count,
			loff_t *ppos)
{
	int ret=0;
	//printk("chrdevbase_read\r\n");
	memcpy(readbuf,kerneldata,sizeof(kerneldata));
	ret = copy_to_user(buf,readbuf,count);
	if(ret ==0){

	}else{

	}

	return 0;
}
static ssize_t chrdevbase_write(struct file *filp, const char __user *buf,
			 size_t count, loff_t *ppos)
{
	int ret=0;
	//printk("chrdevbase_write\r\n");
	copy_from_user(writebuf,buf,count);
	if(ret==0){
		printk("kernel recieve data: %s\r\n",writebuf);

	}else{

	}

	return 0;

}
static int chrdevbase_open(struct inode *inode, struct file *filp)
{
	//printk("chrdevbase_open\r\n");
	return 0;


}

static int chrdevbase_release(struct inode *inode, struct file *filp)
{
	//printk("chrdevbase_release\r\n");

	return 0;
}

static struct file_operations chrdevbase_fops={
	.owner	= THIS_MODULE,
	.open = chrdevbase_open,
	.release = chrdevbase_release,
	.read = chrdevbase_read,
	.write = chrdevbase_write,

};

static int __init chrdevbase_init(void)
{
	int ret=0;
	printk("chrdevbase init\r\n");
	/*register char device*/
	ret = register_chrdev(CHRDEVBASE_MAJOR, CHRDEVBASE_NAME, &chrdevbase_fops);
	if(ret < 0)
	{
		printk("chrdevbase init fialed!!!\r\n");

	}
	return 0;
}

static void __exit chrdevbase_exit(void)
{
	unregister_chrdev(CHRDEVBASE_MAJOR, CHRDEVBASE_NAME);
	printk("chrdevbase exit\r\n");
}

/*
模块入口/出口

*/
module_init(chrdevbase_init);/*入口*/
module_exit(chrdevbase_exit);/*出口*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("jzb <bangjz8396@163.com>");



