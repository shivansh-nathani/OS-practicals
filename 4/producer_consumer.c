#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>

//-----------------------------------------------------------------------
sem_t full_sem;
sem_t empty_sem;
pthread_mutex_t buffer_mutex;
int buffer[5], buffer_index;


//-----------------------------------------------------------------------
void * producer(void * n){
	int thread_no = *(int*)n;
	int value = rand()%100;
	sem_wait(&full_sem);
	
	pthread_mutex_lock(&buffer_mutex);
	buffer[buffer_index++] = value;
	pthread_mutex_unlock(&buffer_mutex);	
	
	sem_post(&empty_sem);
	printf("Producer %d has placed the element %d into buffer\n", thread_no, value);
	
	pthread_exit(NULL);

}

//-----------------------------------------------------------------------
void * consumer(void * n){
	int thread_no = *(int*)n;
	int value ;
	sem_wait(&empty_sem);
	
	pthread_mutex_lock(&buffer_mutex);
	value = buffer[--buffer_index];
	pthread_mutex_unlock(&buffer_mutex);	
	
	sem_post(&full_sem);
	printf("Consumer %d has removed the element %d from buffer\n", thread_no, value);
	
	pthread_exit(NULL);

}



//-----------------------------------------------------------------------
int main(){

	pthread_t tid[10];
	int thread[10];
	int i;
	
	sem_init(&full_sem, 0, 5);
	sem_init(&empty_sem, 0, 0);
	pthread_mutex_init(&buffer_mutex, NULL);
	
	for(i=0;i<10;i++){
		thread[i] = i;
		pthread_create(&tid[i], NULL, producer, &thread[i]);
		i++;

		thread[i] = i;
		pthread_create(&tid[i], NULL, consumer, &thread[i]);
	}
	
	for(i=0;i<10;i++){
		pthread_join(tid[i], NULL);
	}
	
	sem_destroy(&full_sem);
	sem_destroy(&empty_sem);
	pthread_mutex_destroy(&buffer_mutex);
	
	return 0;
}

