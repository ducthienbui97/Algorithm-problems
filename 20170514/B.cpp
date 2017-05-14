#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > sold;
set<int> cus[1111];
vector<int> d[2222];
int F[2222][2222];
int vs[2222];
int find(int s,int t) {
    int rep = 0;
    while(true) {
        memset(vs,-1,sizeof vs);
        queue<int> bfs;
        bfs.push(s);
        vs[s] = 0;
        while(!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            for(int v :d[u])
                if(F[u][v] > 0 && vs[v] < 0) {
                    vs[v] = u;
                    bfs.push(v);
                    //cout << u <<"->"<<v<<" "<<F[u][v]<<endl;
                }
        }
        if(vs[t] < 0) break;
        int v = t;
        int Min = 1<<30;
        while(vs[v] != v) {
            int u = vs[v];
            Min = min(Min,F[u][v]);
            v = u;
        }
        if(Min == 1<<30 || Min < 0) break;
        rep += Min;
        v = t;
        while(vs[v] != v) {
            int u = vs[v];
            F[u][v] -= Min;
            F[v][u] += Min;
            v = u;
        }
    }
    return rep;
}
void solve(int nTest) {
    memset(F,0,sizeof F);
    int n,m,c;
    cin >> n >> c >> m;
    for(int i=0; i<= n + c +1; i++)
        d[i].clear();
    sold.resize(m);
    vector<int> cnt(c+1);
    for(auto&v:sold) {
        cin >> v.first >> v.second;
        cnt[v.second] ++;
    }
    sort(sold.begin(),sold.end());
    int l = 0;
    int r = m;
    for(int i=1; i<=c; i++)
        l = max(l,cnt[i]);
    int ans1,ans2;
    while(l <= r) {
        int mid = (l+r)/2;
        bool ok = true;
        for(int i=0; i<mid; i++)
            cus[i].clear();
        for(auto v:sold) {
            if(!ok) break;
            int pos = v.first;
            int csm = v.second;
            for(int j=0;; j++) {
                if(j == mid) {
                    ok = false;
                    break;
                }
                if(cus[j].find(csm) == cus[j].end() && pos > cus[j].size()) {
                    cus[j].insert(csm);
                    break;
                }
            }
        }
        if(ok) {
            ans1 = mid;
            r = mid -1;
        } else l = mid + 1;
    }
    for(int i=0; i<sold.size(); i++) {
        int u = sold[i].first;
        int v = sold[i].second + n;
        d[u].push_back(v);
        d[v].push_back(u);
        F[u][v] ++;
    }
    for(int i=1; i<=n; i++) {
        d[0].push_back(i);
        F[0][i] = ans1;
    }
    for(int i=1; i<=c; i++) {
        d[i+n].push_back(n+c+1);
        F[i+n][n+c+1] = ans1;
    }
    ans2 = m - find(0,n+c+1);
    cout <<"Case #"<<nTest<<": " << ans1 <<' '<<ans2<<'\n';
}
main() {
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

