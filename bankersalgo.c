
// Banker's Algorithm 
#include <stdio.h> 
int main() 
{ 
    int i, j, k; 
    int pr,res;
    int count=0;
    printf("Enter the number of processes:");
    scanf("%d",&pr);
    printf("Enter the number of resources");
    scanf("%d",&res);
	int alloc[pr][res];
	int max[pr][res];
	int need[pr][res]; 
	int avail[4];
	printf("Enter the allocation table\n");
    for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		scanf("%d",&alloc[x][v]);
		}
	}
	printf("Entered Allocation table is as follows:\n");
	for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		printf("%d \t",alloc[x][v]);
		}
		printf("\n");
	}
	printf("Enter the max table\n");
	for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		scanf("%d",&max[x][v]);
		}
    	
	}
	printf("Entered Maximum table is as follows:\n");
	for(int x=0;x<pr;x++)
    {
    	for(int v=0;v<res;v++)
    	{
    		printf("%d \t",max[x][v]);
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
			need[i][j] = max[i][j] - alloc[i][j];       //calculation of need table
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
                         goto x;
                         else
                         break; 
                    } 
                } 
  
                if (flag == 0) 
				{ 
                    ans[ind++] = i; 
                    for (y = 0; y < res; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
    printf("Following is the SAFE Sequence\n"); 
    for (i = 0; i < pr - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[pr - 1]); 
    return (0); 
        x:
    	printf("Unsafe");
    	return(0);
  
    // This code is contributed by Deep Baldha (CandyZack) 
} 
