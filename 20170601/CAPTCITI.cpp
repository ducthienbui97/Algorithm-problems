#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5e4+20;
long long F[Maxn][2];
vector<int> d[Maxn];
int P[Maxn],C[Maxn];
priority_queue<long long> pr[Maxn];
void dfs(int u,int p){
    long long p0 = 0;
    long long p1 = 0;
    for(int v:d[u]) if(v!=p){
        dfs(v,u);
        p0 += F[v][1];
        pr[u].push(F[v][0] - F[v][1]);
        p1 += F[v][0] - F[v][1];
        if(pr[u].size() > C[u]){
            p1 -= pr[u].top();
            pr[u].pop();
        }
    }
    F[u][0] = F[u][1] = p0 + P[u];
    if(pr[u].size() == C[u]){
        F[u][0] = min(F[u][0],p0 + p1);
        p1 -= pr[u].top();
        pr[u].pop();
    }
    F[u][1] = min(F[u][1],p0 + p1);
    //cout << u <<" "<<F[u][0] <<" "<<F[u][1] <<endl;
}
void solve() {
    memset(F,0,sizeof F);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        d[i].clear();
        while(!pr[i].empty()) pr[i].pop();
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for(int i=1;i<=n;i++) cin >> P[i];
    for(int i=1;i<=n;i++) cin >> C[i];
    dfs(1,0);
    cout <<F[1][0] <<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solve();
}

