#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;

sem_t mutex, empty, full;

void* producer(void* arg) {
    int item;
    int f = ((int)arg);
    
   
    while(1){
        sem_wait(&empty);
        sem_wait(&mutex);

        printf("Enter the item\n");
        scanf("%d", &item);

        buffer[count] = item;
        count++;

        printf("Producer %d produced: %d\n", f, item);
        
        printf("\n");
        
        int i;
        for(i=0; i<BUFFER_SIZE; i++){
        	printf("%d\n",buffer[i]);
        }
        printf("\n");

        sem_post(&mutex); 
        sem_post(&full);
    }
}

void* consumer(void* arg) {
    int item;
    int f = ((int)arg);
    

    while(1){
        sem_wait(&full);
        sem_wait(&mutex);

        count--;
        item = buffer[count];

        printf("Consumer %d consumed: %d\n", f, item);
        
        printf("\n");
        
        int i;
        for(i=0; i<BUFFER_SIZE; i++){
        	printf("%d\n",buffer[i]);
        }
        printf("\n");

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main() {
    
    int i;
    
    pthread_t prod[5], cons[5];

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1); 
    
    for(i=0; i<5; i++){
    	pthread_create(&prod[i], NULL, producer, (void*)i);
    	pthread_create(&cons[i], NULL, consumer, (void*)i);
    }
    
    for(i=0; i<5; i++){
    	pthread_join(prod[i], NULL);
    	pthread_join(cons[i], NULL);
    }
    

    return 0;
}
