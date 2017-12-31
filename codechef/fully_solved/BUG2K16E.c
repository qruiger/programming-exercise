#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define L int long 
int main()
{
    L t, v=1;
    scanf("%ld",&t);
    while(t--)
    {
    	L i, n, k, temp, flag, j, sum=0;
    	scanf("%ld %ld",&n,&k);
     	 for(i=1; i <= n; i++)
     	 {
     	 	if(i%k==0)
     	 	{
     	 		temp = i, flag =0;
     	 		for(j = 1; j<= i; j++)
     	 		{
     	 			if(pow(k,j) == temp)
     	 			{
     	 				flag = 1;
     	 				break;
     	 			}
     	 		}
     	 		if(flag == 0)
     	 			sum+=i;
     	 	}
     	 	else
     	 		sum += i;
     	 }
     	 printf("Case #%ld: %ld\n",v,sum);
     	 v++; 
    }
   return 0; 
}