#include <bits/stdc++.h>

using namespace std;
vector<int>  d[100011];
vector<int> rd[100011];
int F[100011];
int root[100011];
bool vs[100011];
vector<int> vv;
void dfs(int u,vector<int> d[], vector<int> & vv){
    if(vs[u])
        return;
    vs[u] = true;
    for(int v:d[u])
        dfs(v,d,vv);
    vv.push_back(u);
}

main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n;
        cin >> n;
        vv.clear();
        for(int i = 1; i <= n; i++){
            cin >> F[i];
            root[i] = i;
            d[i].clear();
            rd[i].clear();
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            d[u].push_back(v);
            rd[v].push_back(u);
        }
        memset(vs,0,sizeof vs);
        for(int i = 1; i<= n; i++)
            dfs(i,d,vv);
        memset(vs,0,sizeof vs);
        reverse(vv.begin(),vv.end());
        long long ans = 0;
        for(int u:vv){
            vector<int> x;
            dfs(u,rd,x);
            if(x.size() == 0)
                continue;
            int ss = 1<<30;
            for(int v:x){
                ss = min(ss,F[v]);
            }
            ans += ss;
        }
        cout << ans << endl;
    }
}


