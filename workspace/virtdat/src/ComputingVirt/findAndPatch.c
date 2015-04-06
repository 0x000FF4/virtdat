#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/syscalls.h>
#include <asm/errno.h>
#include <asm/unistd.h>
#include <linux/mman.h>
#include <asm/proto.h>
#include <asm/delay.h>
#include <linux/init.h>
#include <linux/highmem.h>
#include <linux/sched.h>
static struct file_operations chdir_ops;
asmlinkage long (*real_chdir)(const char __user *filename);
void (*syscall_handler)(void);
long unsigned int orig_reg;
 
struct	s_descriptorIDT
{
unsigned short	offset_lo;
unsigned short	seg_selector;
unsigned char	reserved;
unsigned char	flag;
unsigned short	offset_hi;
};
struct desc_ptr	idtr;
gate_desc *idt_table;

unsigned long	get_idt_addr(void)
{

unsigned long	idt;
asm ("sidt %0" : "=m" (idtr));
idt_table = (gate_desc *) idtr.address;
return (idt);
}
 
int __init
chdir_init(void){
 
    unsigned int low = 0, high = 0, lo=0;
    unsigned long address;
 	int i = 0;
	gate_desc *idt_table;	
    struct s_descriptorIDT *idt;
   /* rdmsr(0xC0000000,low,high);
    printk("Low:%x\tHigh:%x\n", low,high);
    address = 0;
    address |= high;
    address = address << 32;
    address |= low;
    orig_reg = address;
    */
   	
    address = get_idt_addr();	
    printk("Syscall22 Handler: %d \n", &idt_table[0x80]);
//address = address >> 16;
/*idt = (struct s_descriptorIDT*) address;
for(i = 117; i<135;i++){
if(i!=127){
idt[128].offset_hi = (unsigned short)(0>> 16);
idt[128].offset_lo = (unsigned short)(0 & 0x0000FFFF);
}}*/
    //syscall_handler = (void (*)(void)) address;
 
    //lo = (unsigned int) (((unsigned long)fake_syscall_dispatcher)
    //             & 0xFFFFFFFF);
    printk("Lo: %x\tHi:%x\n", lo,high);
 
   // asm volatile ("wrmsr" :: "c"(0xC0000000), "a"(lo),
   //            "d"(high) : "memory");
 
    return 0;
}
 
void __exit
chdir_cleanup(void){
    printk("Exit\n");
 
   // asm volatile ("wrmsr" :: "c"(0xC0000000),
   //       "a"((unsigned int) (orig_reg & 0xFFFFFFFF)),
   //       "d"(0xffffffff) : "memory");
    return;
}
 
static struct file_operations chdir_ops= {
    .owner  = THIS_MODULE,
};
module_init(chdir_init);
module_exit(chdir_cleanup);
MODULE_LICENSE("GPL");
 

