#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int arr1[3][3];
int arr2[3][3];
int res[3][3];

struct v {
   int i;
   int j;
};

int sum;
void* result(void *arg);

int main() {

   pthread_t tid;
   int i,j,res1=0;
   void *status = NULL;
   struct v *data = (struct v *) malloc(sizeof(struct v));

   printf("Enter the first matrix\n");
   for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
         scanf("%d",&arr1[i][j]);

   printf("Enter the second matrix\n");

   for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
         scanf("%d",&arr2[i][j]);

   for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++) {

         data->i = i;
         data->j = j;

         pthread_create(&tid,NULL,result,data);
         pthread_join(tid,&status);

        res1=*((int*)status);
        printf("\nsum is: %d",res1);
        res[data->i][data->j] =res1;

      }
   }


   printf("\nThe resulting matrix is: \n");
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         printf("%d ", res[i][j]);
      }
      printf("\n");
   }
}


void* result(void *arg)
{
    struct v *data = arg;
    int k;

    sum = 0;

    for(k = 0; k < 3; k++)
          sum += arr1[data->i][k] * arr2[k][data->j];

      pthread_exit(&sum);
}


