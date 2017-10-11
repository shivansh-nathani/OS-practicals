#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int first, last, middle,array[20];
	int i,k,search;
	
	int n = atoi(argv[1]);	
			
	for(i=0; i<n ; i++)
	{
		k = atoi(argv[i+2]);
		array[i] = k;
	}
	
	printf("\nEnter the number you want to search: ");
    scanf("%d",&search);	
   
	first = 0;
	last = n - 1;
  	middle = (first+last)/2;

  	while (first <= last) 
  	{
   	if (array[middle] < search)
   		first = middle + 1;
     	
     	else if (array[middle] == search) 
     	{
       	printf("Found at location: %d\n", middle+1);
        	break;
     	}
     
     	else
       	last = middle - 1;

     	middle = (first + last)/2;
  	}
  
  	if (first > last)
   	printf("Not found!\n");
}








