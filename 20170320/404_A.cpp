#include <bits/stdc++.h>
using namespace std;
vector<int> cl;
vector<vector<int> > d;
void dfs(int u,int p){
    int c = 1;
    for(int v:d[u])
    if(v!=p){
        while(c == cl[u]||c==cl[p]) ++c;
        cl[v] = c++;
    }
    for(int v:d[u])if(v!=p) dfs(v,u);
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    d.resize(n+1);
    cl.resize(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    cl[1] = 1;
    dfs(1,0);
    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans,cl[i]);
    cout << ans <<endl;
    for(int i=1;i<=n;i++)
        cout << cl[i] <<' ';
}
