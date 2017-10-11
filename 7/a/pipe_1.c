
#include<stdio.h>
#include<unistd.h>
int  main()
{
	pid_t cpid;
	int fd[2];
	int fd1[2];
	char buffer[100];
	char msg[100]="test.txt";
	pipe(fd1);
	char buff[100];
	char buffer1[100];
	pipe(fd);
	cpid=fork();
	if(cpid==0)
	{
	
		close(fd[0]);
		write(fd[1],msg,sizeof(msg));
		close(fd1[1]);
		read(fd1[0],buff,sizeof(buffer1));
		printf("%s",buff);
	}
	else
	{
		close(fd[1]);
		read(fd[0],buffer,sizeof(msg));
		close(fd1[0]);
		FILE *fp;
		fp=fopen(buffer,"r");
		fgets(buffer1,20,fp);
		
		write(fd1[1],buffer1,20);
	}	
	
}
