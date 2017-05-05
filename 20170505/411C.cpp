#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e5+20;
vector<int> ic[Maxn];
vector<int> d[Maxn];
int col[Maxn],prs[Maxn];
void dfs(int u,int p){
    int color = 1;
    for(auto&c:ic[u]) if(col[c]) prs[col[c]] = u;
    for(auto&c:ic[u]) if(!col[c]){
        while(prs[color] == u) color ++;
        col[c] = color;
        prs[color] = u;
    }
    for(int v:d[u]) if(v!=p) dfs(v,u);
}
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int s;
        cin >> s;
        ic[i].resize(s);
        for(auto&c:ic[i]) cin >> c;
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    dfs(1,0);
    int ans = 0;
    for(int i=1;i<=m;i++){
        if(!col[i]) col[i] =1;
        ans = max(ans,col[i]);
    }
    cout << ans <<endl;
    for(int i=1;i<=m;i++)
        cout <<col[i] << " ";
}


