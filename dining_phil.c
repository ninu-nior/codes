#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void dine(int n);//dine function is defined which will be used later
pthread_t philosopher[5];//array of threads for philosophers
pthread_mutex_t forks[5];//array of mutexes representing the forks

int main(){
int i,status;
for(int i=0;i<5;i++){
status=pthread_mutex_init(&forks[i],NULL);//initializes each mutex in fork array
if(status!=0){
printf("error in mutex initialization");}
}
for(int i=0;i<5;i++){
status=pthread_create(&philosopher[i],NULL,(void*)dine,(int*)i);
//this loop creates a thread for each philosopher, it passes the dine function as the thread function and the philosopher's index i as an argument
}
for(int i=0;i<5;i++){
status=pthread_join(philosopher[i],NULL);
//this loop waits for each philosopher to finist execution 

}
for(int i=0;i<5;i++){
status=pthread_mutex_destroy(&forks[i]);
}
}
void dine(int n){
printf("philosopher %d is thinking\n",n);
pthread_mutex_lock(&forks[n]);
pthread_mutex_lock(&forks[(n+1)%5]);
printf("philosopher %d is eating\n",n);
sleep(3);
pthread_mutex_unlock(&forks[n]);
pthread_mutex_unlock(&forks[(n+1)%5]);
printf("philosopher %d finished eating\n",n);
}
