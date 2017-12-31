#include<stdio.h>
#define LL long long int
int main()
{
 int T;
 scanf("%d",&T);
 while(T--)
 {
  LL n,i,j,k=0,c=0,max=0;
  int p=0,count=0,flag=0;
  scanf("%lld",&n);
  LL x[n],b[n];
  char a[n+1];
  scanf("%s",a);
  for(i=0;i<n;i++)
 { 	
  scanf("%lld",&x[i]);
  if(a[0]=='0' && p==0)
  {
  	count++;
  	if(count>1)
    c+=x[i]-x[i-1];	
  	if(a[i]=='1')
  		p=1;
  }
   if(a[i]=='1')
    {
     if(i>0)
     {
        if(a[i+1]=='0' || a[i-1]=='0')
       {   
        b[k]=i;
        k++;
       }
     }
     if(i==0)
     { 
      b[k]=i;
      k++;
     }
    }
 }
/* for(i=0;i<k;i++)
 {
 	printf("%lld  ",b[i]);
 }
 printf("\n");*/
 if(a[n-1]=='0')
 {
 	flag=1;
 	for(i=n-1;i>0;i--)
 	{
 		c+=x[i]-x[i-1];
 		if(a[i-1]=='1')
 			break;
    }
 }
  for(i=0;i<k-1;i++)
 { 	
 	 max=0;	
 	    for(j=b[i];j<=b[i+1];j++)
  	  {	
  		  c+=x[j+1]-x[j];
        if(max<(x[j+1]-x[j]))
    	  max=(x[j+1]-x[j]);
        if(a[j+1]=='1')
        {
        	c-=max;
        	break;
        } 
      }
    
 }
 printf("%lld \n",c);
}
return 0;
} 