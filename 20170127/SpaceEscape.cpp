#include <bits/stdc++.h>
#define U first.first
#define V first.second
#define COS second.first
#define MAX second.second
using namespace std;
set<pair<pair<long long,long long>,int > > vs;
int n,m,t;
const int b1 = 101;
const int b2 = 103;
int ans;
typedef pair<pair<int,int>,pair<int,int>> edge;
vector<int> d[22];
vector<edge> e;
long long hs(vector<int>& mo,int base){
    long long rep = 0;
    for(auto&value:mo) rep = rep*base + value;
    return rep;
}
void dfs(int u,vector<int>& mo){
    pair<long long,long long> cur = make_pair(hs(mo,b1),hs(mo,b2));
    if(vs.find(make_pair(cur,u)) != vs.end()) return;
    vs.insert(make_pair(cur,u));
    if(u==n-1) ans = max(ans,mo[u]);
    for(int i=0;i<d[u].size();i++){
        if(mo[u] < e[d[u][i]].COS) continue;
        int v;
        if(u == e[d[u][i]].V) v = e[d[i][i]].U;
        else v = e[d[u][i]].V;
        int carry = min(mo[u]-e[d[u][i]].COS,e[d[u][i]].MAX);
        mo[u]-=(e[d[u][i]].COS+carry);
        mo[v]+=carry;
        dfs(v,mo);
        mo[u]+=(e[d[u][i]].COS+carry);
        mo[v]-=carry;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> t;
    e.resize(m);
    for(int i=0;i<m;i++){
        cin >> e[i].U >> e[i].V >> e[i].COS >> e[i].MAX;
        e[i].U --;
        e[i].V --;
        d[e[i].U].push_back(i);
        d[e[i].V].push_back(i);
    }
    ans = -1;
    vector<int> money(n);
    money[0] = t;
    dfs(0,money);
    cout << ans;
}
