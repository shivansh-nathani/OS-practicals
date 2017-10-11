#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{
int shm_id;
key_t key;
int *shm_ptr;
int ret_val,data;
key=100;
shm_id=shmget(key,4096,IPC_CREAT|0666);

if (shm_id<0)
{
printf("shmget ERROR");
exit(-1);
}
else
{
printf("shared memory created\n");
printf("shared memory id is %d\n",shm_id);
shm_ptr=(int*)shmat(shm_id,NULL,0);
if((int)*shm_ptr != -1)
{
//printf("memory is attached at process = %d\n",shm_ptr);
}
printf("enter the data\n");
scanf("%d",&data);
*shm_ptr=data;
int i;
while(*shm_ptr!='a')
{
	
}
printf("%d",*shm_ptr);
}
ret_val=shmdt((void*)shm_ptr);
if(ret_val==0)
{
printf("shared memory is sucessfully detached\n"); 
}
else
{
printf("error\n");
}

}

