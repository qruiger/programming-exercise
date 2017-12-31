#include<stdio.h>
#include<math.h>
#define L int long
int main()
{
    	L t, p = 1,a[10001], i, v=1;
    	scanf("%ld",&t);
    	for(i=1;i<=10000;i++)
	{
		a[i] = p;
		p+=9;
	}	
    	while(t--)
    	{	
		L leap = 0, n, temp=0;
		scanf("%ld",&n);
		for(i=1;i<=10000;i++)
		{
			if(n>temp)
			{
				leap++;
			}
			else
			{
				break;
			}
			temp+=a[i];
		}
		printf("Case #%ld: %ld\n",v,leap);
		v++; 
    	}
   	return 0; 
}
