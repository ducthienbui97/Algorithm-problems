#include <bits/stdc++.h>
using namespace std;
const int Maxn =  1e5+20;
vector<int> d[Maxn];
int cnt[Maxn];
int c[Maxn];
void dfs(int u,int p){
    for(int v:d[u]){
        cnt[u] += (c[v] != c[u]);
        if(v!=p) dfs(v,u);
    }
}
bool check(int u,int p){
    for(int v:d[u])
    if(v!=p){
        if(c[v]!=c[u]) return false;
        if(!check(v,u)) return false;
    }
    return true;
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        d[u].push_back(v);
        d[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        cin >>c[i];
    dfs(1,0);
    int Max = 1;
    for(int i=2;i<=n;i++)
        if(cnt[i] > cnt[Max]) Max = i;
    bool ok = true;
    for(int u:d[Max]) ok&=check(u,Max);
    cout << (ok?"YES":"NO") <<endl;
    if(ok) cout << Max;
}
