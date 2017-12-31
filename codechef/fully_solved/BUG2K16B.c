#include<stdio.h>
#include<math.h>
int main()
{
	int t;
    	scanf("%d",&t);
    	while(t--)
    	{
    		int n,i,max=0;
     		scanf("%d",&n);
     		int a[n], b[100] = {0};
     		for(i=1;i<=n;i++)
     		{	
     			scanf("%d",&a[i]);
     			b[a[i]]++;
     			if(max<a[i])
     				max=a[i];
     		}
     		for(i=1;i<=max;i++)
     		{
     			if(b[i]!=0)
     				printf("%d: %d\n",i,b[i]);
     		}
	}
   	return 0; 
}
