#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int range;
void *getrange(void *value)
{

	printf("Welocme the first thread.\n\nEnter the number you wish to get prime numbers for: ");
  scanf("%d",&range);
	return NULL;
}
void *prime(void *disp)
{
  sleep(10);
  int i;
 printf("\nThis is start of second thread. \n\nThe number you entered is :%d",range);
 printf("\nPrime numbers are:-\n");    
    for(i=2;i<=range;i++)
    {
        int c=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                c++;
            }
        } 
       if(c==2)
        {
            printf("%d\n",i);
        }
    }
 return NULL;
}

int main()
{
  pthread_t threadone;
  pthread_t threadtwo;
  pthread_create(&threadone,NULL,getrange,NULL);
  pthread_create(&threadtwo,NULL,prime,NULL);
  pthread_exit(NULL);
}