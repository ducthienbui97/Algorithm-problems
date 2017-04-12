#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1111;
int F[Maxn];
bool vs[Maxn];
int dis[Maxn];
vector<int> d[Maxn];
vector<int> topo;
vector<int> scc;
void dfs1(int u){
    if(vs[u]) return;
    vs[u] = true;
    dfs1(F[u]);
    topo.push_back(u);
}
void dfs2(int u){
    if(vs[u]) return;
    vs[u]=true;
    scc.push_back(u);
    for(int v:d[u]) dfs2(v);
}
int bfs(int u,int v){
    memset(dis,0,sizeof dis);
    queue<int> q;
    int ans = 0;
    dis[u] = 1;
    dis[v] = 1;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int v:d[u]) if(!dis[v]) dis[v] = dis[u]+1,q.push(v);
        ans = max(ans,dis[u]);
    }
    return ans;
}
void solve(int nTest){
    topo.clear();
    int n;
    int ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        d[i].clear();
        cin >> F[i];
        vs[i] = false;
    }
    for(int i=1;i<=n;i++){
        d[F[i]].push_back(i);
        dfs1(i);
    }
    reverse(topo.begin(),topo.end());
    int scc_2 = 0;
    memset(vs,0,sizeof vs);
    for(int u:topo){
        dfs2(u);
        if(scc.size() > 2) ans = max(ans,(int)scc.size());
        else if(scc.size() == 2){
            scc_2 += bfs(scc[0],scc[1]) + bfs(scc[1],scc[0]);
        }
        scc.clear();
    }
    ans = max(ans,scc_2);
    cout <<"Case #"<<nTest<<": "<<ans<<endl;;

}
main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
    }

