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

vector<vi> G;
vector<int> dist;
int testcount=1,V,E;
bool homosexual;
void bfs(int start)
{
    if(homosexual) return;
    int i,j,u,v;
    dist[start]=0;
    queue<int> q; q.push(start);
    while(!q.empty())
    {
        u=q.front(); q.pop();
        for(i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(dist[v]==oo)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
            else if((dist[u]-dist[v])%2==0) {homosexual=true; return;}
        }
    }
}
void execute()
{
    homosexual=false;
    int i,j,k,u,v;
    scanf("%d %d",&V,&E);
    G.assign(V,vi());
    for(i=1; i<=E; i++)
    {
        scanf("%d %d",&u,&v);
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dist.assign(V,oo);
    for(i=0; i<V; i++) if(dist[i]==oo) bfs(i);
    if(homosexual) printf("Scenario #%d:\nSuspicious bugs found!\n",testcount++);
    else printf("Scenario #%d:\nNo suspicious bugs found!\n",testcount++);
}

int main()
{
    freopen("BUGLIFE.INP","r",stdin);
    freopen("BUGLIFE.OUT","w",stdout);
    int test;
    scanf("%d",&test);
    while(test--) execute();
    return 0;
}
