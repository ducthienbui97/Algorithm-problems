#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<set>
#define oo 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
                            /*                           END OF TEMPLATE                            */

vector<vii> G;
int V,E,K,cost[10][10][10],Dist[10][1<<7];
vi dist;
map<int,int> num,renum;
void Dijkstra()
{
    int i,j,s,t;
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    for(s=0; s<K; s++)
        for(t=0; t<=K; t++)
        {
            int start=renum[s];
            dist.assign(V,oo);
            dist[start]=0;
            pq.push(ii(0,start));
            while(!pq.empty())
            {
                ii x=pq.top(); pq.pop();
                int u=x.second;
                for(i=0; i<G[u].size(); i++)
                {
                    ii v=G[u][i];
                    if(dist[v.first]>dist[u]+(v.second*(10-t))/10)
                    {
                        dist[v.first]=dist[u]+(v.second*(10-t))/10;
                        pq.push(ii(dist[v.first],v.first));
                    }
                }
            }
            for(i=0; i<K; i++) cost[s][i][t]=dist[renum[i]];
        }
}
void solve()
{
    int i,j,t,ans=oo,s,u;
    for(s=0; s<(1<<K); s++)
        for(i=0; i<K; i++) Dist[i][s]=oo;
    for(i=0; i<K; i++) Dist[i][1<<i]=0;
    for(s=0; s<(1<<K); s++)
    {
        t=__builtin_popcount(s);
        for(u=0; u<K; u++)
            if(s&(1<<u))
                for(j=0; j<K; j++)
                    if(j!=u && s&(1<<j))
                        Dist[u][s]=min(Dist[u][s],Dist[j][s-(1<<u)]+ cost[j][u][t-1]);
    }
    for(u=0; u<K; u++)
        ans=min(ans,Dist[u][(1<<K)-1]);
    printf("%d",ans);
}
int main()
{
    freopen("travel.inp","r",stdin);
    freopen("travel.out","w",stdout);
    int i,j,a,b,w1,w2;
    scanf("%d %d %d",&V,&E,&K);
    G.assign(V,vii());
    for(i=1; i<=E; i++)
    {
        scanf("%d %d %d %d",&a,&b,&w1,&w2);
        a--; b--;
        G[a].push_back(ii(b,w1));
        G[b].push_back(ii(a,w2));
    }
    for(i=0; i<K; i++)
    {
        scanf("%d",&a);
        a--;
        num[a]=i;
        renum[i]=a;
    }
    Dijkstra();
    solve();
    return 0;
}
