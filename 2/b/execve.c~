#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void quick(int array[], int firstIndex, int lastIndex)
{
    int pivotIndex, temp, index1, index2;

    if(firstIndex < lastIndex)
    {
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;

        while(index1 < index2)
        {
            while(array[index1] <= array[pivotIndex] && index1 < lastIndex)
            {
                index1++;
            }
            while(array[index2]>array[pivotIndex])
            {
                index2--;
            }

            if(index1<index2)
            {
                temp = array[index1];
                array[index1] = array[index2];
                array[index2] = temp;
            }
        }

        temp = array[pivotIndex];
        array[pivotIndex] = array[index2];
        array[index2] = temp;

        quick(array, firstIndex, index2-1);
        quick(array, index2+1, lastIndex);
    }
}

int main()
{
	pid_t pid,p;
	int status,i,j,n,arr[20];
	char *str[20];

	printf("\nEnter the no of elements: ");
	scanf("%d",&n);

	printf("\nEnter the nos: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	quick(arr,0,n-1);	// Sorting

	char *ch;
	asprintf(&ch, "%d", n);
	str[1] = ch;

	for(i=0;i<n;i++)
	{
		char c[sizeof(int)];
		snprintf(c,sizeof(int),"%d",arr[i]);
		str[i+2] = malloc(sizeof(c));
		strcpy(str[i+2], c);
	}

	str[i+2]=NULL;
	str[0]="b";

	pid = fork();

	if(pid == 0)
	{
		execve("/home/shivansh/Desktop/binary",str,NULL);
	}

	else
	{
		p = wait(&status);
		printf("\n\nSorted elements are: \n");

		for(i=0; i<n; i++)
			printf("%d ",arr[i]);

	    printf("\t");
	}

	printf("\n");
}
