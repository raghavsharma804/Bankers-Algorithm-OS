//code Written by Raghav Sharma 
#include <stdio.h> 
#include<unistd.h>
int main() 
{ 
    printf("\n\n\n\t\t\t\tWelcome to Banker's Algorithm Tester\n");
    int i, j, k; 
    int pr,res;
    int count=0;
    printf("\t\tEnter the number of processes:");
    scanf("%d",&pr);
    printf("\t\tEnter the number of resources:");
    scanf("%d",&res);
	int allocation[pr][res];
	int maximum[pr][res];
	int need[pr][res]; 
	int avail[4];
	printf("Enter the allocation table\n");
    for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		scanf("%d",&allocation[x][v]);
		}
	}
	printf("Entered Allocation table is as follows:\n");
	for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		printf("%d \t",allocation[x][v]);
		}
		printf("\n");
	}
	printf("Enter the max table\n");
	for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		scanf("%d",&maximum[x][v]);
		}
    	
	}
	printf("Entered Maximum table is as follows:\n");
	for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		printf("%d \t",maximum[x][v]);
		}
		printf("\n");
	}
    printf("\nEnter Available resources:\n");
    for(int z=0;z<res;z++)
    scanf("%d",&avail[z]); // Available Resources 
  
    int f[pr], ans[pr], ind = 0; 
    for (k = 0; k < pr; k++) { 
        f[k] = 0; 
    } 
    //NEED TABLE ENTRY
    for (i = 0; i < pr; i++) 
	{ 
        for (j = 0; j < res; j++)  
            {
			need[i][j] = maximum[i][j] - allocation[i][j];       //calculation of need table
			if(need[i][j]<0)   //if need is negetive than it will be counted as zero rather than negetive
			need[i][j]=0;
		    }
    }  
    printf("Need table generated and is as follows:\n");
    for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		printf("%d \t",need[x][v]);
		}
		printf("\n");
	}
    int y = 0; 
    for (k = 0; k < 5; k++) 
	{ 
        for (i = 0; i < pr; i++) 
		{ 
            if (f[i] == 0) 
			{ 
                int  flag = 0;   //flag set to 0
                for (j = 0; j < res; j++) { 
                    if (need[i][j] > avail[j])  
					//check if need is greater than available
                    //if yes then skip this process
					{ 
                         flag = 1; 
                        count=count+1;
                         if(count>pr)     
						 //if all the needs are greater than the available resources then the counter will move to label x that will terminate the program.
                         goto x;
                         else
                         break; 
                    } 
                } 
  
                if (flag == 0) 
				{ 
                    ans[ind++] = i; 
                    for (y = 0; y < res; y++) 
                        avail[y] += allocation[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
    printf("\n\n\nThe system is in safe state.\nThe order of process is\n"); 
    for (i = 0; i < pr - 1; i++) 
        printf(" P%d-", ans[i]); 
    printf(" P%d", ans[pr - 1]); 
    return (0); 
        x: //label x
    	printf("\n\n\t\t\t\tA deadlock has occured and It is unsafe state!!!\n");
    	return(0);
} 
//code Written by Raghav Sharma 
