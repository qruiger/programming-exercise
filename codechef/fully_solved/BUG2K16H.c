#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void quicksort(char *x,int first,int last)
{
	int pivot,j,temp,i;
	if(first<last)
     	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(x[i]<=x[pivot]&&i<last)
		 		i++;
			while(x[j]>x[pivot])
		 		j--;
			if(i<j)
			{
				temp=x[i];
		  		x[i]=x[j];
		  		x[j]=temp;
			}
		}
 		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
		quicksort(x,first,j-1);
		quicksort(x,j+1,last);
 
    	}
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	char s[51],temp;
        scanf("%s",s);
        int l = strlen(s), i, count, flag = 0, j;
        quicksort(s, 0, l-1);
        for(i=0;i<l;)
        {
            flag =0;
        	if(s[i+1] == s[i])
        	{
        		flag =1;
        		temp = s[i],count=0;
        		printf("%c",s[i]);
        		j = i;	
        		while(s[j+1] == temp)
        		{	
        			count++;
        			j++;
        		}
        		count++;
        		printf("%d",count);
        	}
        	else
        	printf("%c",s[i]);
        	if(flag==1)
        		i+=count;
        	else
        		i++;	
        }
        printf("\n");	
    }
   return 0; 
} 
