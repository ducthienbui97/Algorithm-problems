#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<pair<int,int> > c;
vector<int> g;
vector<int> d;
const int inf = 1<<30;
bool ok(int cap){
    int time = 0;
    for(auto dis:d){
        if(cap < dis) return false;
        if(cap >= 2*dis) time += dis;
        else time += 3*dis - cap;
    }
    return time <= t;
}
main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    c.resize(n);
    g.resize(m);
    for(auto&v:c){
        cin >> v.second >> v.first;
    }
    for(auto&v:g){
        cin >> v;
    }
    sort(c.begin(),c.end());
    g.push_back(0);
    g.push_back(s);
    sort(g.begin(),g.end());
    for(int i=1;i<g.size();i++)
        d.push_back(g[i] - g[i-1]);
    int l = 0;
    int r = c.size() -1;
    int piv = inf;
    int ans = inf;
    while(l<=r){
        int mid = (l+r)>>1;
        int cap = c[mid].first;
        if(ok(cap)){
            piv = cap;
            r = mid -1;
        }else{
            l = mid + 1;
        }
    }

    for(int i=0;i<c.size();i++)
        if(c[i].first >= piv && ans > c[i].second) ans =  c[i].second;
    if(ans == inf) ans = -1;
    cout << ans <<endl;
}
