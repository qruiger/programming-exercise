#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL int long long
LL a[50005],b[50005],c[50005],n,maxindex,smaxindex,maxval=0,smaxval=0,m=0,ind;
LL bsearch(LL *ss,LL left,LL  right,LL element)
{
   if(right>=left)
   {
        LL mid=left+(right-left)/2;
        if(ss[mid]>element) 
            return bsearch(ss,left,mid-1,element);
        if(ss[mid]==element)  
            return mid;
        return bsearch(ss,mid+1,right,element);
   }
   return -1;
}
struct node
{
    LL dest;
    struct node* next;
};
struct list
{
    struct node* head;
};
struct graph
{
    LL v;
    struct list *array;
};
struct node* newnode(LL dest)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->dest=dest;
    new_node->next=NULL;
    return new_node;
}
struct graph* creategraph(LL v)
{
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->v=v;
    g->array=(struct list*)malloc(v*sizeof(struct list));
    LL i;
    for (i=1;i<=v;i++)
        g->array[i].head=NULL;
    return g;
}
void addedge(struct graph* g, LL src, LL dest)
{
    struct node* newNode=newnode(dest);
    newNode->next=g->array[src].head;
    g->array[src].head=newNode;
    newNode=newnode(src);
    newNode->next=g->array[dest].head;
    g->array[dest].head=newNode;
}
void print(struct graph* g)
{
    LL i,k;
    LL temp[50005]={0};
   for(i=1;i<=g->v;i++)
   {
        m=0;
        temp[i]++;
        struct node* x=g->array[i].head;
        struct node* y;
        y=x;
        m=a[m]<a[i]?i:m;
        while(x)
        {
            temp[x->dest]++;
            m=a[m]<a[x->dest]?x->dest:m;
            x=x->next;
        }
        if(a[m]<maxval)
        {
            printf("%lld ",maxindex);
        } 
        if(a[m]==maxval)
        { 
            for(k=n;k>=1;k--)
            {   
                if(temp[c[k]]==0)
                {
                    printf("%lld ",c[k]);
                    break;
                }
            }   
        }
        temp[i]=0;
        while(y)
        {
            temp[y->dest]=0;
            y=y->next;
        }   
   }
}  
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        LL i,count[50005]={0},flag=0,v,u;
        maxval=0,smaxval=0,m=0;
        scanf("%lld",&n);
        struct graph* g = creategraph(n);
        a[0]=-1;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            if(maxval<a[i])
            {
                smaxval=maxval;
                smaxindex=maxindex;
                maxval=a[i];
                maxindex=i;
            }
            if(a[i]>smaxval && a[i]!=maxval)
            {
                smaxval=a[i];
                smaxindex=i;
            }
        }
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&v,&u);
            count[v]++;
            count[u]++;
            addedge(g,v,u);
        }
        for(i=1;i<=n;i++)
        {
            if(count[i]==n-1)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        for(i=1;i<=n;i++)
            b[i]=a[i];
        sort(b+1,b+n+1);
        for(i=1;i<=n;i++)
        {
            ind=bsearch(b,1,n,a[i]);
            c[ind]=i;
        }
        print(g);
        printf("\n");
    }
    return 0; 
}   