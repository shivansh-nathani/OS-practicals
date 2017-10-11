#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
//---------------------------------------------------------------

pthread_mutex_t x;
pthread_mutex_t wsem;

int readcount = 0;
char fn[20];
//--------------------------------------------------------------
void* writer(void * n){
	int thread_no = *(int*)n;
	char txt;
	FILE *fp;
	
	pthread_mutex_lock(&wsem);
	
	printf("Writer %d : Enter the filename : \n", thread_no);
	scanf("%s", fn);
	
	fp = fopen(fn, "a");
	
	printf("Enter the data to the file -> ");
	scanf("%c", &txt);
	
	do{
	
		fputc(txt, fp);
		scanf("%c", &txt);
		
	}while(txt != '#');
	
	fclose(fp);

	pthread_mutex_unlock(&wsem);
	pthread_exit(NULL);

}

//--------------------------------------------------------------
void* reader(void * n){
	int thread_no = *(int*)n;
	char txt;
	FILE *fp;
	
	pthread_mutex_lock(&x);
	readcount++;
	
	if(readcount == 1)
			pthread_mutex_lock(&wsem);
			
	pthread_mutex_unlock(&x);
	
	printf("Reader %d : Enter the filename :\n", thread_no);
	scanf("%s", fn);
	
	fp = fopen(fn, "r");
	
	while( !feof(fp)){
	
		txt = fgetc(fp);
		printf("%c", txt);	
	
	}
	fclose(fp);
	
	pthread_mutex_lock(&x);
	readcount--;
	
	if(readcount == 0)
			pthread_mutex_unlock(&wsem);

	pthread_mutex_unlock(&x);
	pthread_exit(NULL);

}
//--------------------------------------------------------------
int main()
{
	pthread_t tid[10];
	int t[10];
	int i;
	
	pthread_mutex_init(&x, NULL);
	pthread_mutex_init(&wsem, NULL);
	
	for(i=0;i<10;i++){
		t[i] = i;
		pthread_create(&tid[i], NULL, reader, &t[i]);
		
		i++;

		t[i] = i;
		pthread_create(&tid[i], NULL, writer, &t[i]);
	}
	
	for(i=0;i<10;i++){
		pthread_join(tid[i], NULL);
	}
	
	pthread_mutex_destroy(&x);
	pthread_mutex_destroy(&wsem);
	
	return 0;
}
