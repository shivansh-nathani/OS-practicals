#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int main()
{
	int fd,fd1;

	fd=open("trial",O_CREAT|O_RDWR,0666);
	printf("%d",fd);
	close(fd);



	 	struct stud
	 	{
	 		int roll;
	 		char name[10];
	 	}s1,s2;
	 	int ch;
	 	int bytesread;
	 	do
	 	{
	 		printf("\n1.enter\n2.dispaly all\n3.search record\n4.update\n5.delete\n6.exit");
	 		scanf("%d",&ch);
	 		switch(ch)
	 		{
	 			case 1:

	 				fd=open("trial",O_WRONLY);
					write(fd,&s1,sizeof(s1));
					printf("enter roll no");
					scanf("%d",&s1.roll);
					printf("enter name");
				 	scanf("%s",s1.name);
				 	write(fd,&s1,sizeof(s1));
					close(fd);
					break;
				case 2:
					fd=open("trial",O_RDONLY);

					while(read(fd,&s2,sizeof(s1))){


							//printf("record present");
							printf("%d",s2.roll);
							printf("%s\n",s2.name);




					}
					close(fd);

					break;
				case 3:
					printf("enter the roll no to be searcherd");
					int rolls;
					scanf("%d",&rolls);
					fd=open("trial",O_RDONLY);
					int bytesread;
					do
					{
					bytesread=read(fd,&s2,sizeof(s1));
					if(rolls==s2.roll)
						{
							printf("record present");
							printf("%d",s2.roll);
							printf("%s",s2.name);
							break;

						}

					}while(bytesread==sizeof(s1));
					close(fd);
					break;
				case 4:
					printf("enter the roll no to be updated");
					scanf("%d",&rolls);
					fd=open("trial",O_RDWR);

					while(read(fd,&s2,sizeof(s1))){

						if(rolls==s2.roll)
						{
							printf("record present");
							lseek(fd,0-sizeof(s1),SEEK_CUR);
							printf("enter new roll no");
							scanf("%d",&s1.roll);
							printf("\nenter new name");
				 			scanf("%s",s1.name);
				 			write(fd,&s1,sizeof(s1));
							break;

						}

					}
					break;
				case 5:
					printf("enter the roll no to be deleted");
					scanf("%d",&rolls);
					fd=open("trial",O_RDWR);
					fd1=open("temp",O_CREAT|O_RDWR,0666);
					while(read(fd,&s2,sizeof(s1))){


						if(rolls==s2.roll)
						{



						}
						else
						{
							//read(fd,&s2,sizeof(s1));
							write(fd1,&s2,sizeof(s1));
						}

					}
					close(fd);
					close(fd1);
					remove("trial");
					rename("temp","trial");
					break;
			}

	 		}while(ch!=6);




}

















































