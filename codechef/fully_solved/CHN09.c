#include<stdio.h>
#include<string.h>
int main()
{
	int n,T,i,a,b,l;
	char s[101];
	scanf("%d",&T);
	while(T--)
	{
	a=0;b=0;
	scanf("%s",s);	
    l=strlen(s);
    for(i=0;i<l;i++)
     {
     	if(s[i]=='a')
     		a+=1;
     	if(s[i]=='b')
     		b+=1;
     }
      if(a>b)
     	printf("%d\n",b);
     else 
     	printf("%d\n",a);
    }  
    return 0;

}