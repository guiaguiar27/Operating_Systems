// Guilherme Aguiar SIlva MIlanez - 3496 - guilherme.aguiar@ufv.br
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>  
#include <time.h>
#define Param_random 1000   
#define Vector_size 100 
#define  Num_threads 10 
// váriaveis globais compartilhadas entre as threads  
// vetores   
// para cada thread há um vetor de tamanho vector_size 
int Vector[Num_threads][Vector_size]; 
int tick = 0;   

void *Fill_Vector1(void *x){   
    int aux;
    aux = *((int *) x);
    // os vetores são preenchidos com numeros aleatorios  
    if(tick == 0){ 
        srand((unsigned)time(NULL)); 
        printf("Vector %d :",aux); 
        for(int i = 0 ; i<Vector_size ; i++){
            Vector[aux][i] = rand()%Param_random; 
            printf("%d ",Vector[aux][i]);
        
        }   
        printf("\n"); 
    sleep(1);
    tick = 1 ;  
    }   
      
    pthread_exit(NULL);
}
// identifica os primos no vetor 
void *Prime_vectors(void *x){  
    // calcula em qual vetor está analisando 
    int aux;
    aux = *((int *) x); 
    // mudança 
    if(tick == 1 ){
        int counter = 0 ;   
        int d, prime ;     
        // identifica os primos no vetor 1 
        for(int i = 0 ; i<Vector_size ; i++){  
            d = 2 ; prime = 1 ;
            if(Vector[aux][i] <=1 ) prime = 0 ;  
            while(prime ==1 && d <= Vector[aux][i]/2){ 
                if (Vector[aux][i]%d == 0) prime = 0 ;   
                d = d +1 ;  
            } 

            if(prime == 1 ){ 
                counter++ ; 
                
            }       
        }      

    printf("Vetor %d possui %d primos\n\n",aux,counter); 
    tick = 0 ;
    pthread_exit(NULL);
    } 

}  
/*
void common_primes(void max_vectors){  
    int num_vec = 0 ;   
    while(num_vec <= max) 

}  
*/ 
 
// Dado dois vetores com valores randomicos no intervalo de 0 a 100 quantos números primos os dois tem em comum  
int run(){ 
    int create[Num_threads] ; 
    pthread_t Thread_Vector[Num_threads]; 
    int thread_args[Num_threads]; 
    printf("\n\nPreenche vetores:\n"); 
    // a cada iteração duas threads são acionadas , uma para o vetor outra para a identificação dos numeros primos  
    for(int i = 1; i < Num_threads + 1 ; i++ ){
        thread_args[i] = i;  
        create[i] = pthread_create(&Thread_Vector[i],NULL,Fill_Vector1,(void *)&thread_args[i]); 
        create[i] = pthread_join(Thread_Vector[i], NULL); 
        create[i] = pthread_create(&Thread_Vector[i],NULL,Prime_vectors,(void *)&thread_args[i]); 
        create[i] = pthread_join(Thread_Vector[i], NULL);
    } 
    
    return 0; 
}
int main(){  
    run();  
    
    return 0; 
}