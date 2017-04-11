#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e5+20;
vector<int> d[Maxn];
int maxChild[Maxn],sz[Maxn];
int ans[Maxn];
int p[Maxn];
void dfs(int u){
    for(int v:d[u]){
        dfs(v);
        sz[u] += sz[v];
        if(sz[v] > sz[maxChild[u]]) maxChild[u] = v;
    }
    sz[u]++;
    if(sz[maxChild[u]]*2 <= sz[u]) ans[u]=u;
    else{
        int tmp = ans[maxChild[u]];
        while(max(sz[maxChild[tmp]],sz[u]-sz[tmp])*2 > sz[u]) tmp =  p[tmp];
        ans[u] = tmp;
    }
}

main(){
    ios_base::sync_with_stdio(false);
    int n,q;

    cin >> n >> q;
    for(int i=2;i<=n;i++){
        cin >> p[i];
        d[p[i]].push_back(i);
    }
    dfs(1);
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        cout << ans[x] <<endl;
    }
}
