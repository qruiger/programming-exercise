#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n,i,b;
       char p[4];
       scanf("%d %s",&n,p);
       int a[n];
       if(n==1)
       { 	
        scanf("%d",&b);  
        if(b%2==0 && p[1]=='e')
        printf("Dee\n");
        else 
        printf("Dum\n") ;
        continue;
       }		
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       printf("Dum\n");
    }
   return 0; 
}