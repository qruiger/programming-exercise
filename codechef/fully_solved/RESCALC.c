#include <stdio.h>
#include <stdlib.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,i,k=1,f=1,range=0,z,sum,flag,m[101],index[101],winner,j,p,max,s,q;
    int c[101],type[101];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      z=0,sum=0;int count[7]={0};
      scanf("%d",&c[i]);
      for(j=1;j<=c[i];j++)
      {  
        scanf("%d",&type[j]);
        count[type[j]]++;
      }
      /*for(j=1;j<=6;j++)
      printf("%d ",count[j]);
      printf("\n"); */ 
      for(j=1;j<=6;j++)
      {
        if(count[j]==0)
        z++;        
      }
      if(z>2)
      {
        //printf("zeroes=%d\n",z);
        //printf("Final sum=%d\n",c[i]);
        m[k++]=c[i];
        index[f++]=i;
        range++;
      }
      if(z<=2)
      {
         while(1)
        {
          p=0;
          for(q=1;q<=6;q++)
          {
            if(count[q]!=0)
            {
              count[q]--;
              p++;
            }
          }
          /*printf("After decrementing array\n");
          for(s=1;s<=6;s++)
          printf("%d ",count[s]);
          printf("\n");
          printf("p=%d\n",p);*/
          if(p<4)
          break;  
          else
          {
            if(p==6)
              sum+=4;
            if(p==5)
              sum+=2;
            if(p==4)
              sum+=1;
            //printf("additional points=%d\n",sum);  
          }
        }
          //printf("Final sum=%d\n",sum+c[i]);
          m[k++]=(sum+c[i]);
          index[f++]=i;
          range++;
      }
    }
    /*for(i=1;i<=range;i++)
      printf("%d ",m[i]);
    printf("\n");
    for(i=1;i<=range;i++)
      printf("%d ",index[i]);
    printf("\n");*/
    max=0,flag=1;
    for(i=1;i<=range;i++)
    {
      if(max==m[i])
      {
        flag++;
      }
      if(max<m[i])
      {
        max=m[i];
        winner=index[i];
        flag=0;
      }
    }
      //printf("%d\n",max);
      if(flag==0)
      {
        if(winner==1)
          printf("chef\n");
        else
          printf("%d\n",winner);  
      }
      else
      printf("tie\n");
  }
  return 0;
}