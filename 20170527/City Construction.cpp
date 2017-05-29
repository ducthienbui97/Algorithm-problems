#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5e4+20;
vector<int> d[Maxn];
vector<int> rev_d[Maxn];
vector<tuple<int,int,int> > query;
map<int,long long> mp[Maxn];
int pr[Maxn];
int vs[Maxn];
vector<int> s;
void dfs(int u){
    vs[u] = true;
    for(int v:d[u])
        if(!vs[v]) dfs(v);
    s.push_back(u);
}
void dfs2(int u,int p){
    pr[u] = p;
    for(int v:rev_d[u])
        if(!pr[v]) dfs2(v,p);
}
void dfs3(int u){
    vs[u] = 2;
    for(int v:d[u]){
        if(vs[v] < 2) dfs3(v);
        if(pr[u] != pr[v])
            for(auto&it:mp[pr[v]]){
                mp[pr[u]][it.first] |= it.second;
            }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        rev_d[y].push_back(x);
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int x,y,z;
        cin >> x >> y >>z;
        query.emplace_back(x,y,z);
        if(x==1){
            n++;
            if(z){
                d[n].push_back(y);
                rev_d[y].push_back(n);
            }else{
                d[y].push_back(n);
                rev_d[n].push_back(y);
            }
        }
    }
    for(int i=1;i<=n;i++)
    if(!vs[i]) dfs(i);
    reverse(s.begin(),s.end());
    for(int u:s)
        if(!pr[u]){
            mp[u][u/60] |= (1ll<<(u%60));
            dfs2(u,u);
        }
    for(int u:s)
        if(vs[u]<2)dfs3(u);
    for(int i=0;i<q;i++){
        int x,y,z;
        x = get<0>(query[i]);
        if(x == 2){
            y = get<1>(query[i]);
            y = pr[y];
            z = get<2>(query[i]);
            z = pr[z];
            if(mp[y][z/60]&(1ll<<(z%60)))
                cout <<"Yes" <<endl;
            else
                cout <<"No" <<endl;
        }
    }
}
