#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

int data = 0; // Shared resource
int readers_count = 0; // Number of active readers

pthread_mutex_t mutex; // Mutex for critical section
sem_t rw_mutex; // Semaphore for controlling access to data

void *reader(void *param);
void *writer(void *param);

int main() {
    pthread_t reader_threads[NUM_READERS];
    pthread_t writer_threads[NUM_WRITERS];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&rw_mutex, 0, 1);

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_create(&reader_threads[i], NULL, reader, NULL);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_create(&writer_threads[i], NULL, writer, NULL);
    }

    // Join reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    // Join writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}

void *reader(void *param) {
    while (1) {
        pthread_mutex_lock(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_mutex); // Acquire read access
        }
        pthread_mutex_unlock(&mutex);

        // Read data
        printf("Reader read data: %d\n", data);

        pthread_mutex_lock(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&rw_mutex); // Release read access
        }
        pthread_mutex_unlock(&mutex);

        sleep(1); // Sleep for some time
    }
}

void *writer(void *param) {
    while (1) {
        sem_wait(&rw_mutex); // Acquire write access

        // Write data
        data++;
        printf("Writer wrote data: %d\n", data);

        sem_post(&rw_mutex); // Release write access

        sleep(2); // Sleep for some time
    }
}
