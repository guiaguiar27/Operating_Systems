
#define MAX 100  
#define TRUE 1 
typedef int semaforo;   
typedef int Item ;   
semaforo mutex, empty, full; 
mutex = 1 ; 
empty = MAX; 
full = 0; 
void produtor(void) { 
    Item item ; 
    while(TRUE) { 
        item = produz(); 
        Down(&empty); 
        Down(&mutex); 
        insere(item); 
        Up(&mutex); 
        Up(&full); 
    } 
}  
void consumidor(void){ 
    Item item ; 
    while(TRUE){ 
        Down(&full); 
        Down(&mutex); 
        item = remove(); 
        Up(&mutex); 
        Up(&empty); 
        item = consome();  
    }     
}

 





