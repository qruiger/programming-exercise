#include<stdio.h>
int main()
{
	int temp,n,rev,count,T,L,R,i,r,sum;
	scanf("%d",&T);
	while(T--)
	{
		count=0;
		sum=0;
		scanf("%d%d",&L,&R);
		for(i=L;i<=R;i++)
		{
			temp=i;
			n=i;
			rev=0; 
			while(n>0)
			{
				r=n%10;
				rev=(rev*10)+r;
				n/=10;
			}
         		if(rev==temp)
         			sum+=temp;
		}
		printf("%d\n",sum);
    	}
	return 0;
}
