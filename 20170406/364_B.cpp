#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5+20;
int n,k;
vector<int> d[Maxn];
bool uni[Maxn];
int cnt[Maxn];
long long ans;
void dfs(int u,int p){
    for(v:d[u]) if(v!=p){
        dfs(v,u);
        cnt[u] += cnt[v];
    }
    cnt[u]+=uni[u];
    if(p) ans += min(cnt[u],2*k-cnt[u]);
}
main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0; i<2*k; i++) {
        int x;
        cin >> x;
        uni[x] = true;
    }
    for(int i=1; i<n; i++) {
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    dfs(1,0);
    cout << ans;
}
