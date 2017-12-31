#include<stdio.h>
#define LL long long int 
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
     	LL k,p,i,j,n,c,v;
        int flag=0;
     	scanf("%lld",&k);
     	n=k;
        c=(k+1)/2;
 		for(i=1;i<=n;i++)
 		{
            flag=0;
 			for(j=1;j<=n;j++)
 			{
 				if(i==j)
                {
                    printf("%lld ",c);
                    flag=1;
                    p=c;
                }
                if(i!=j && flag==1)
                {
                    p++;
                    if(p>n)
                        p=1;
                    printf("%lld ",p);
                    v=p;
                }
                if(i!=j && flag==0)
                {
                    printf("%lld ",v++);
                    if(v>n)
                        v=1;
                }
            }
 			printf("\n");
 		}
    }
   return 0; 
}