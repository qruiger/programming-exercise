#include <bits/stdc++.h>
using namespace std;
#define LL int long long
typedef pair<LL,LL> LL_pair;
list< pair<LL,LL> > *adj_list;
LL V;
void create_list() 
{
    adj_list=new list< pair<LL,LL> >[V];
}
void connect_extranode(LL u,LL v,LL w)
{
    adj_list[u].push_back(make_pair(v,w));
    adj_list[v].push_back(make_pair(u,0));
}
void add_edge(LL u,LL v,LL w)
{
    adj_list[u].push_back(make_pair(v,w));
    adj_list[v].push_back(make_pair(u,w));
}
void shortest_path(LL s)
{
    priority_queue< LL_pair,vector<LL_pair>,greater<LL_pair> > pqueue;
    vector<LL> dist(V,LLONG_MAX);
    pqueue.push(make_pair(0,s));
    dist[s]=0;
    while(pqueue.size()) 
    {
        LL u=pqueue.top().second;
        pqueue.pop();
        list<LL_pair>::iterator i;
        i=adj_list[u].begin();
        while(i!=adj_list[u].end()) 
        {
            LL v=i->first;
            LL w=i->second;
            if(dist[v]>dist[u]+w) 
            {
                dist[v]=dist[u]+w;
                pqueue.push(make_pair(dist[v],v));
            }
            i++;
        }
    }
    LL i=1;
    while(i<V-1)
        printf("%lld ",dist[i++]);
    printf("\n");
}
int main()
{
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        LL n,i,k,x,m,u,v,wt,s,j;
        scanf("%lld %lld %lld %lld %lld",&n,&k,&x,&m,&s);
        V=n+2;
        create_list();
        for(i=1;i<=k;i++)
        {
            connect_extranode(i,n+1,x);
        }
        while(m--)
        {
            scanf("%lld %lld %lld",&u,&v,&wt);
            add_edge(u,v,wt);
        }
        shortest_path(s);
    }
    return 0; 
} 