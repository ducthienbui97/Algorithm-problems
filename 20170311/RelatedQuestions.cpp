// https://www.quora.com/about/challenges
#include <bits/stdc++.h>

using namespace std;
vector<int> t;
vector<double> F,G;
vector<vector<int> > d;
vector<int> p;
void dfs1(int u){
    for(auto v:d[u])
    if(v!=p[u]){
        p[v] = u;
        dfs1(v);
        F[u] += t[v];
        if(d[v].size() > 1) F[u] += F[v]/(d[v].size() - 1);
    }
}
void dfs2(int u,double T){
    G[u] = (F[u] + T)/d[u].size() + t[u];
    for(auto v:d[u])
    if(v!=p[u]){
        double tmp = T + F[u] - t[v];
        if(d[v].size() > 1) tmp -= F[v]/(d[v].size() - 1);
        if(d[u].size() > 1) tmp = tmp / (d[u].size() -1) + t[u];
        dfs2(v,tmp);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    t.resize(n);
    F.resize(n);
    G.resize(n);
    d.resize(n);
    p.resize(n);
    for(int i=0;i<n;i++)
        cin >> t[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >>y ;
        --x,--y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    p[0] = -1;
    dfs1(0);
    dfs2(0,0);
    int ans = 0;
    for(int i=1;i<n;i++)
        if(G[i] < G[ans]) ans = i;
    cout << ans + 1 <<endl;

}
