#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      int i,j,l,c,e,o;
      scanf("%d %d",&l,&c);
      for(i=1;i<=l;i++)
      {
      	e=0,o=0;
      	if(i%2==0)
      	{	
      	 e=1;
      	 printf(".");
      	}
      	if(i%2!=0)
        {
        	o=1;
        	printf("*");
        }	
        if(e==1)
        {
           for(j=1;j<c;j++)
          {
            if(j%2!=0)
            printf("*");
            else
            printf(".");
          }
        }
        if(o==1)
        {
           for(j=1;j<c;j++)
          {
           if(j%2!=0)
            printf(".");
           else
            printf("*");
          } 
        }	
      	printf("\n");
      }
    }
   return 0; 
}#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      int i,j,l,c,e,o;
      scanf("%d %d",&l,&c);
      for(i=1;i<=l;i++)
      {
      	e=0,o=0;
      	if(i%2==0)
      	{	
      	 e=1;
      	 printf(".");
      	}
      	if(i%2!=0)
        {
        	o=1;
        	printf("*");
        }	
        if(e==1)
        {
           for(j=1;j<c;j++)
          {
            if(j%2!=0)
            printf("*");
            else
            printf(".");
          }
        }
        if(o==1)
        {
           for(j=1;j<c;j++)
          {
           if(j%2!=0)
            printf(".");
           else
            printf("*");
          } 
        }	
      	printf("\n");
      }
    }
   return 0; 
}