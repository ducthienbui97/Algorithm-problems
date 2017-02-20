#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<bitset>
#include<set>
#include<climits>
#include<deque>
#include<utility>
#include<functional>
#include<istream>
#include<ostream>
#include<memory>
#include<locale>
#include<cassert>
#include<iterator>
#define oo 1000000000
#define base 1000000007ll
#define MAX 1005
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
/*                                                          End of template                                                                */

vector<vii> G;
int V,E,start,target;
vector<int> dist,trace,ans;
void Dijkstra()
{
    int i,j,u,k;
    dist.assign(V,0);
    trace.assign(V,-1);
    dist[start]=oo;
    priority_queue<ii,vector<ii>,less<ii> > pq; pq.push(ii(oo,start));
    while(!pq.empty())
    {
        ii x=pq.top(); pq.pop();
        int d=x.first; u=x.second;
        for(i=0; i<G[u].size(); i++)
        {
            ii v=G[u][i];
            if(dist[v.first]<min(v.second,d))
            {
                dist[v.first]=min(v.second,d);
                trace[v.first]=u;
                pq.push(ii(dist[v.first],v.first));
            }
        }
    }
    if(dist[target]==0) {printf("-1"); return;}
    printf("%d\n",dist[target]);
    int t=target;
    while(t!=start)
    {
        ans.push_back(t+1);
        t=trace[t];
    }
    printf("%d\n",ans.size()+1);
    printf("%d ",start+1);
    for(i=ans.size()-1; i>=0; i--) printf("%d ",ans[i]);
}

int main()
{
    freopen("UNESCO.INP","r",stdin);
    freopen("UNESCO.OUT","w",stdout);
    int i,j,a,b,w;
    scanf("%d %d %d %d",&V,&E,&start,&target);
    G.assign(V,vii());
    start--; target--;
    for(i=1; i<=E; i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        a--; b--;
        G[a].push_back(ii(b,w));
        G[b].push_back(ii(a,w));
    }
    Dijkstra();
    return 0;
}
