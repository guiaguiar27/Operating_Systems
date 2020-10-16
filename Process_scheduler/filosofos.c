#define N        5
#define ESQUERDA (i+N-1)%N  
#define DIREITA  (i+1)%N 
#define PENSANDO 0  
#define FAMINTO  1  
#define COMENDO  2 
#define TRUE 1  
typedef int Semaforo;  
// uma estado para cada filosofo 
int estado[N]; 
Semaforo Mutex = 1;  /*vetor de semaforo para cada estado */ Semaforo S[N]; 
void tenta(int i){ 
    if(estado[i] == FAMINTO && estado[ESQUERDA] != COMENDO && estado[DIREITA] != COMENDO){ estado[i] = COMENDO; Up(&S[i]); }
}
void P_Garfo(int i ){ 
    // operacao atomica do mutex , bloqueia os outro para acessar a região critica 
    Down(&Mutex); 
    estado[i] = FAMINTO;  
    // tentativa de alocar recurso (pegar garfo)
    tenta(i); 
    Up(&Mutex); Down(&S[i]); 
} 
void D_Garfo(int i){ 
     Down(&Mutex);  
     estado[i] = PENSANDO; 
     tenta(ESQUERDA); tenta(DIREITA);  // ve quem vai ser o proximo a comer
     Up(&Mutex); 
}
void filosofo(int i ){ 
    while(TRUE){  
        // estado de espera 
        pensar();  
        //aloca recurso
        P_Garfo(i);  
        // usa recurso
        comer();  
        // devolve recurso
        D_Garfo(i);
    }
} 
