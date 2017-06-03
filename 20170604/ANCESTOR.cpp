#include <bits/stdc++.h>
using namespace std;
const int maxn = 555000;
int BIT[maxn];
vector<int> d1[maxn],d2[maxn];
int l[maxn],r[maxn];
int ans[maxn];
int cnt;
void update(int x,int v){
    for(;x<=cnt;x+=x&-x) BIT[x]+=v;
}
int get(int x){
    int rep = 0;
    for(;x>0;x-=x&-x) rep += BIT[x];
    return rep;
}
void dfs1(int u,int p = 0){
    l[u] = ++ cnt;
    for(auto&v:d1[u]) if(v != p) dfs1(v,u);
    r[u] = cnt;
}
void dfs2(int u,int p = 0){
    //cout << u <<endl;
    ans[u] = get(l[u]);
    update(l[u],1);
    update(r[u]+1,-1);
    for(auto&v:d2[u]) if(v!=p) dfs2(v,u);
    update(l[u],-1);
    update(r[u]+1,1);
}
void solve(){
    int n;
    cin >> n;
    cnt=0;
    for(int i=1;i<=n;i++){
        d1[i].clear();
        d2[i].clear();
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        d1[x].push_back(y);
        d1[y].push_back(x);
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        d2[x].push_back(y);
        d2[y].push_back(x);
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=n;i++)
        cout << ans[i] <<' ';
    cout <<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}


