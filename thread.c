//code written by RAGHAV SHARMA K18AW 
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>    //contains all the libraries required of threads in C
int range;             //global variable range declared
void *getrange(void *value)    //start of the first thread
{

  printf("\n\t\t\t\tWelocme the first thread.\n\n\t\t\t\tPlease Enter the number you wish to get prime numbers for: Range=");   //asks the user for entering the range
  scanf("%d",&range);    //scans the range integer and saves
  
  printf("\n\n\t\t\t\tYour request is saved. This is the end of Thread-1");  //end of thread-1 message
	return NULL;
} //end of thread-1
void *prime(void *disp)  //start of thread 2
{
  int i;  //for interating of loop
 printf("\n\n\n\t\t\t\tWelcome to the second thread.");
 printf("\n\n\t\tPrime numbers that exist between 0 to %d are as follows:-\n",range);    
    for(i=2;i<=range;i++)   //start of for loop for checking prime numbers.
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
            printf("\t\t%d\n",i);
        }
    }
 return NULL;
}

int main()
{
  pthread_t threadone; //declaration of Thread-1
  pthread_t threadtwo;  //declaration of Thread-2
  pthread_create(&threadone,NULL,getrange,NULL); //creation of Thread-1:
  pthread_join(threadone,NULL);
  pthread_create(&threadtwo,NULL,prime,NULL);
  pthread_exit(NULL);
} //code written by RAGHAV SHARMA K18AW 
