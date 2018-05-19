#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,vector<pair<int,int> > > h;
map<pair<int,int>, pair<int,int> > p;
set<pair<int,int> > vs;
bool dfs(pair<int,int> u) {
    if(vs.find(u) != vs.end())
        return false;
    vs.insert(u);
    for(auto&v:h[u]) {
        if(p.find(v) == p.end() || dfs(p[v])) {
            p[v] = u;
            return true;
        }
    }
    return false;
}
void solve(int t) {
    h.clear();
    p.clear();
    int n,ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            int v;
            cin >> v;
            h[ {i,v}].push_back({j,v});
        }
    for(auto&u:h) {
        vs.clear();
        ans += dfs(u.first);
    }

    cout << "Case #" << t << ": " << n*n - ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}

