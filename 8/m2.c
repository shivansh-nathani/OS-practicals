#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{
int shm_id;
key_t key;
int *shm_ptr;
int ret_val,read_data;
key=100;
shm_id=shmget(key,4096,0666);

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
//printf("memory is attached at process = %x\n",shm_ptr);
read_data=*shm_ptr;
printf("data from shared memory is %d\n",*shm_ptr);
*shm_ptr='a';
}
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

