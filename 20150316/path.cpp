#include<stdio.h>
#include<string.h>
#define fi first
#define se second
#define M 1500
#define NM 5000
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> II;
int f[M + 20];
int g[M + 20];
int ans[NM + 20];
int mod = 1000000007;
vector<ii> E[M + 20];
vector<ii> G[M + 20];
vector<II> edge;
priority_queue<ii , vector<ii> , greater<ii> > pq;
int d[M + 20];
int INF = 1e9;
int n,m,start;
int cal_down(int u){
    if(f[u] != -1) return f[u];
    int res = 1;
    for(int i = 0 ; i < E[u].size() ; i++){
        int v = E[u][i].fi;
        int c = E[u][i].se;
        if(d[v] == d[u] + c) res = (res + cal_down(v))%mod;
    }
    return f[u] = res;
}
int cal_up(int u){
    if(g[u] != -1) return g[u];
    if(u == start) return g[u] = 1;
    int res = 0;
    for(int i = 0 ; i < G[u].size() ; i++){
        int v = G[u][i].fi;
        int c = G[u][i].se;
        if(d[u] == d[v] + c) res = (res + cal_up(v))%mod;
    }
    return g[u] = res;
}
void dijstrka(){
    for(int i = 1 ; i <= n ; i++) d[i] = INF;
    for(int i = 1 ; i <= n ; i++){
        f[i] = -1 ; g[i] = -1;
    }
    d[start] = 0;
    pq.push(ii(d[start],start));
    while(!pq.empty()){
        int dist = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if(dist != d[u]) continue;
        for(int i = 0 ; i < E[u].size() ; i++){
            int v = E[u][i].fi;
            int c = E[u][i].se;
            if(d[v] > d[u] + c){
                d[v] = d[u] + c;
                pq.push(ii(d[v],v));
            }
        }
    }
    for(int i = 0 ; i < edge.size() ; i++){
        int u = edge[i].se.fi;
        int v = edge[i].se.se;
        int c = edge[i].fi;
        if(d[v] == d[u] + c) ans[i] = (ans[i] + 1ll*cal_down(v)*cal_up(u))%mod;
    }
}
void solve(){
    scanf("%d %d",&n,&m);
    for(int i = 1 ; i <= m ; i++){
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        E[u].push_back(ii(v,c));
        G[v].push_back(ii(u,c));
        edge.push_back(II(c,ii(u,v)));
    }
    for(int i = 1 ; i <= n ; i++){
        start = i;
        dijstrka();
    }
    for(int i = 0 ; i < m ; i++)    printf("%d\n",ans[i]);
}
main(){
   // freopen("test.inp","r",stdin);
    solve();
}
