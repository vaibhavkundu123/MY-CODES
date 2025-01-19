#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by each thread
void* threadFunction(void* arg) {
    int thread_id = ((int)arg);
    printf("Hello from thread %d\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];  // Array to hold thread identifiers
    int thread_args[5];    // Array to hold arguments for each thread
    int result;

    // Create 5 threads
    for (int i = 0; i < 5; i++) {
        thread_args[i] = i + 1;  // Set thread argument (1-based index)
        result = pthread_create(&threads[i], NULL, threadFunction, (void*)thread_args[i]);
        if (result != 0) {
            printf("Error creating thread %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished.\n");
    return 0;
}

