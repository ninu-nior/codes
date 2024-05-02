#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

pthread_mutex_t mutex;
sem_t full, empty;

void *producer(void *param);
void *consumer(void *param);
void insert_item(int item);
int remove_item();

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}

void *producer(void *param) {
    int item;
    while (1) {
        item = rand() % 100; // Generate a random item
        sem_wait(&empty); // Wait for an empty slot
        pthread_mutex_lock(&mutex); // Lock the buffer
        insert_item(item); // Insert the item into the buffer
        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&full); // Signal that a slot is filled
        printf("Produced: %d\n", item);
        sleep(1); // Sleep for some time
    }
}

void *consumer(void *param) {
    int item;
    while (1) {
        sem_wait(&full); // Wait for a filled slot
        pthread_mutex_lock(&mutex); // Lock the buffer
        item = remove_item(); // Remove an item from the buffer
        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&empty); // Signal that a slot is empty
        printf("Consumed: %d\n", item);
        sleep(2); // Sleep for some time
    }
}

void insert_item(int item) {
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
}

int remove_item() {
    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    return item;
}
