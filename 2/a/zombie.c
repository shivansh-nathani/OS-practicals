/*Zombie State*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int *status=NULL;
	pid_t cpid;
	cpid = fork();
	if( cpid == 0 )
	{

		printf("\n\t This is child process. ");
		printf("\n\t My process id is : %d", getpid());
		printf("\n\t My Parent process id is : %d\n", getppid());
	}
	else
	{
		sleep(5);

		printf("\n\t My process id is : %d", getpid());
		printf("\n\t My Parent process id is : %d\n", getppid());
	}
return 0;
}
