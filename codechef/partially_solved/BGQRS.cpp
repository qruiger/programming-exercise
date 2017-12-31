#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LL long long int
# define lim 100001
LL SegTree[4*lim]; LL a[lim];
LL x,y,k;
void ConstSegTree(LL input[], LL low, LL high, LL pos)
{
  if(low == high)
  {
    SegTree[pos] = input[low];
    //printf("pos=%lld element=%lld\n",pos,SegTree[pos]);
    return;
  }
  LL mid = (low+high)/2;
  ConstSegTree(input, low, mid, 2*pos+1);
  ConstSegTree(input, mid+1, high, 2*pos+2);
  SegTree[pos] =  SegTree[2*pos+1] * SegTree[2*pos+2];
  //printf("pos=%lld element=%lld\n",pos,SegTree[pos]);
}
LL MultRangeQuery( LL qlow, LL qhigh, LL low, LL high, LL pos)
{
   if(qlow <= low && qhigh >= high) 
	return SegTree[pos];
   if(qlow > high || qhigh < low) 
    return 1;
   LL mid = (low+high)/2;
   return MultRangeQuery(qlow, qhigh, low, mid, 2*pos+1) * 
          MultRangeQuery(qlow, qhigh, mid+1, high, 2*pos+2);
}
void UpdateValX(LL qlow, LL qhigh, LL low, LL high, LL pos)
{
  if(qlow > high || qhigh < low)
    return;
  if(low == high)
  {
    SegTree[pos] *= x;
    //printf("leaf val=%lld\n",SegTree[pos]);
    return;
  }
  LL mid = (low+high)/2;
  UpdateValX(qlow, qhigh, low, mid, 2*pos+1);
  UpdateValX(qlow, qhigh, mid+1, high, 2*pos+2);
  SegTree[pos] = SegTree[2*pos+1] * SegTree[2*pos+2];
}
void UpdateValY(LL qlow, LL qhigh, LL low, LL high, LL pos)
{
  if(qlow > high || qhigh < low)
    return;
  if(low == high)
  {
  	k++;
    SegTree[pos] = y*k;
    return;
  }
  LL mid = (low+high)/2;
  UpdateValY(qlow, qhigh, low, mid, 2*pos+1);
  UpdateValY(qlow, qhigh, mid+1, high, 2*pos+2);
  SegTree[pos] = SegTree[2*pos+1] * SegTree[2*pos+2];
}
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
		LL type,i,low,n,m,rise,mult=0,z=0,count=0;
 		scanf("%lld %lld",&n,&m);
 		for(i=0;i<n;i++)
 			scanf("%lld",&a[i]);
 		ConstSegTree(a, 0, n-1, 0);
 		while(m--)
 		{
 			scanf("%lld %lld %lld",&type,&low,&rise);
 			low--;rise--;
 			if(type == 1)
 			{
 				scanf("%lld",&x);
 				UpdateValX(low, rise, 0, n-1, 0); 
 			}
 			if(type == 2)
 			{
 				k=0;
 				scanf("%lld",&y);
 				UpdateValY(low, rise, 0, n-1, 0);
 			}
 			if(type == 3)
 			{
 				mult = MultRangeQuery(low, rise, 0, n-1, 0);
 				//printf("mult=%lld\n",mult);
 				z=0;
 				while(mult%10 == 0)
 				{
 					z++;
 					mult/=10;
 				}
 				count+=z;
 				//printf("zeros=%lld\n",z);	
 			}	
 		}
 		printf("%lld\n",count);
    }
   return 0; 
} 
