#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      int i,l;char k[201];
      scanf("%s",k);
      l=strlen(k);
      for(i=0;i<l/2;i++)
      {
      	if(i==0)
      	printf("%c",k[0]);
      	if(i>0 && i%2==0)
      	printf("%c",k[i]);	
      }
      printf("\n");	
    }
   return 0; 
}