// the registers xv6 will save and restore
// to stop and subsequently restart a process
struct context { 
    int eip; 
    int esp; 
    int ebx;  
    int ecx;  
    int edx;  
    int esi;  
    int edi; 
    int ebp; 

};  
// possible states of thre process 
enum process_state { UNUSED, EMBRYO , SLEEPING, RUNNABLE, RUNNING, ZOMBIE}; 
struct process{ 
    char *mem ; 
    int sz; 
    char *kstack; 
    struct process *parent ;  
    void *chan ;  
    int killed ;  
    struct file *oile[]; 
    struct inode *cwd;  
    struct context context ; 
    struct trapframe *tf;   

}; 