#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
#define LL int long long
#define N 1000001
int A[N];
int main()
{
    int t,a,b,c,d,e,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        for(b=0;b<a;b++)
        {
            scanf("%d",&A[b]);
        }
        int cnt=1,flag=0;
        for(b=1;b<a;b++)
        {
            if(A[b-1]==A[b])
            {
                cnt++;
            }
            if(A[b-1]!=A[b])
            {
                cnt=1;
            }
            if(cnt==3)
            {
                printf("Yes\n");
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("No\n");
    }
    return 0;     
} 
