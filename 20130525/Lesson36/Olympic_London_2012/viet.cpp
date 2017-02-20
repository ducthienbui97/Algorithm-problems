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

int V,E,start,target,ans=oo;
vector<vii> G;
vi ds,df;
void Dijkstra()
{
    int i,j,u;
    ds.assign(V,oo);
    df.assign(V,oo);
    ds[start]=0;
    df[target]=0;
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    pq.push(ii(0,start));
    while(!pq.empty())
    {
        ii front=pq.top(); pq.pop();
        u=front.second;
        for(i=0; i<G[u].size(); i++)
        {
            ii v=G[u][i];
            if(ds[v.first]>ds[u]+v.second)
            {
                ds[v.first]=ds[u]+v.second;
                pq.push(ii(ds[v.first],v.first));
            }
        }
    }
    pq.push(ii(0,target));
    while(!pq.empty())
    {
        ii front=pq.top(); pq.pop();
        u=front.second;
        for(i=0; i<G[u].size(); i++)
        {
            ii v=G[u][i];
            if(df[v.first]>df[u]+v.second)
            {
                df[v.first]=df[u]+v.second;
                pq.push(ii(df[v.first],v.first));
            }
        }
    }
}

int main()
{
    freopen("Olympic_London_2012.inp","r",stdin);
    freopen("Olympic_London_2012.out","w",stdout);
    int i,j,a,b,w;
    scanf("%d %d %d %d",&V,&E,&start,&target);
    G.assign(V,vii());
    start--;
    target--;
    for(i=1; i<=E; i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        a--; b--;
        G[a].push_back(ii(b,w));
        G[b].push_back(ii(a,w));
    }
    Dijkstra();
    for(i=0; i<V; i++)
        for(j=0; j<G[i].size(); j++)
            ans=min(ans,ds[i]+df[G[i][j].first]);
    if(ans==oo) printf("-1");
    else printf("%d",ans);
    return 0;
}
