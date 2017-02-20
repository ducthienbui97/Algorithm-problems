#include <bits/stdc++.h>
using namespace std;
vector<int> d[111000];
int low[111000],dis[111000];
int p[111000];
int b[111000];
void dfs(int u){
    int childs = 0;
    low[u] = dis[u] = dis[p[u]] + 1;
    for(int i=0;i<d[u].size();i++){
        int v = d[u][i];
        if(v==p[u]) continue;
        if(dis[v]) low[u] = min(low[u],dis[v]);
        else {
            ++childs;
            p[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(!p[u] && childs >= 2) b[u] = true;
            else if(p[u] && low[v] >= dis[u]) b[u] = true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    string s;
    cin >> n >> m;getline(cin,s);
    for(int i=0;i<m;i++){
        getline(cin,s);
        for(int i=0;i<s.size();i++)
            if(s[i] < '0' || s[i] >'9') s[i] = ' ';
        stringstream ss(s);
        int x,y;
        ss >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    if(!dis[i]) dfs(i);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(!b[x]) puts("Happy Jack");
        else puts("Sad Jack");
    }
}
