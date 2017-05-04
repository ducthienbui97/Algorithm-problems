#include <bits/stdc++.h>
using namespace std;
vector<int> d[111];
vector<pair<pair<int,int>,int> > ed;
int dis[111][111];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pr;
int n,m;
void find(int t){
    while(!pr.empty()) pr.pop();
    for(int i=0;i<n;i++)
        dis[t][i] = 1<<30;
    dis[t][t] = 0;
    pr.push(make_pair(0,t));
    while(!pr.empty()){
        int u = pr.top().second;
        int w = pr.top().first;
        pr.pop();
        if(dis[t][u] < w) continue;
        for(int e:d[u]){
            int v;
            if(u == ed[e].first.first) v = ed[e].first.second;
            else v = ed[e].first.first;
            int we = ed[e].second;
            if(we + w < dis[t][v]){
                dis[t][v] = we + w;
                pr.push(make_pair(we+w,v));
            }
        }
//        cout << dis[t][u] <<" "<<t <<" "<<u <<endl;
    }
}
void solve(int nTest) {
    cin >> n >> m;
    ed.resize(m);
    for(int i=0;i<n;i++)
        d[i].clear();
    for(int i=0;i<m;i++){
        cin >> ed[i].first.first >> ed[i].first.second >> ed[i].second;
        d[ed[i].first.first].push_back(i);
        d[ed[i].first.second].push_back(i);
    }
    cout << "Case #"<<nTest<<":\n";
    for(int i=0;i<n;i++)
        find(i);
    int ans = 0;
    for(int i=0;i<m;i++){
        bool ok = false;
        int u = ed[i].first.first;
        int v = ed[i].first.second;
        int w = ed[i].second;
        for(int l = 0; l < n && !ok;l++)
            for(int r = 0; r < n && !ok; r++)
                if(dis[l][u] + w + dis[v][r] == dis[l][r]){
                    ok = true;
                }
        if(!ok) cout << i <<endl;
    }
}
main() {
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}




