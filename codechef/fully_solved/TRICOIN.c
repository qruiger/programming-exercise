#include<stdio.h>
int main()
{
	int sum,T,N,i,count;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		sum=0;
		count=0;
		for(i=1;;i++)
		{
			count+=1;    	
			sum+=i;
			if(sum==N)
			{
				printf("%d\n",count);
				break;
			}
			if(sum>N)
			{
				printf("%d\n",count-1);
				break;
			}
		} 
	}
	return 0;
}
