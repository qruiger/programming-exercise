#include<stdio.h>
#include<string.h>
#define LL int long long
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	char a[100001];
    	LL l, i, n, o = 0, z = 0;
    	scanf("%s",a);
    	l = strlen(a);
    	if(l == 1)
    	{
    		printf("Yes\n");
    		continue;
    	}
    	for(i=0;i<l;i++)
    	{
    		if(a[i] == '0')
    			z++;
    		else
    			o++;
    	}
    	if(z == 0 || o == 0)
    	{
    		printf("No\n");
    		continue;
    	}
    	if(o == 1 || z == 1)
    		printf("Yes\n");
    	else
    		printf("No\n");
    }
   return 0; 
}