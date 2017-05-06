#include <bits/stdc++.h>
using namespace std;
set<pair<long long,long long> > P;
vector<int> gp,ge,gt;
void solve(int nTest) {
    P.clear();
    int np,ne,nt,m;
    cin >> np >> ne >> nt;
    gp.resize(np);
    ge.resize(ne);
    gt.resize(nt);
    for(auto&g:gp) cin >> g;
    for(auto&g:ge) cin >> g;
    for(auto&g:gt) cin >> g;
    for(auto g1:gp)
    for(auto g2:gt){
        int u = __gcd(g1,g2);
        P.emplace(g1/u,g2/u);
    }
    cin >> m;
    cout << "Case #"<<nTest<<":"<<endl;
    while(m-->0){
        long long x,y;
        cin >> x >>y;
        bool ok = false;
        for(int i=0;i<ne&&!ok;i++)
        for(int j=0;j<ne&&!ok;j++) if(i!=j){
            long long p = x*ge[i];
            long long q = y*ge[j];
            long long u = __gcd(p,q);
            if(P.find(make_pair(p/u,q/u)) != P.end()) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }



}
main() {
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}



