#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
typedef pair<pii,int> piii;
const int Max = 50;
int pr[Max];
const int Maxn = 2e4+20;
long long id[Maxn];
map<long long,int> id2idx;
vector<pii> d[Maxn];
pii dist[Maxn];
priority_queue<piii> hep;
int n,m;
vector<long long> primes;
long long get(long long val) {
    return upper_bound(primes.begin(),primes.end(),val) - primes.begin();
}
long long dis(int src,int des) {
    for(int i = 0; i < n; i++)
        dist[i] = {1ll<<62,0};
    hep.push({{0,get(id[src])},src});
    dist[src] = {0,get(id[src])};
    while(!hep.empty()) {
        long long _dis = - hep.top().first.first;
        long long _gol = hep.top().first.second;
        int idx = hep.top().second;
        hep.pop();
        if(dist[idx].first < _dis|| _gol < dist[idx].second)
            continue;
        for(auto&u:d[idx]) {
            int nx_idx = u.second;
            long long nx_dis = _dis + u.first;
            long long nx_gol = _gol + get(id[nx_idx]);

            if(nx_dis < dist[nx_idx].first) {
                dist[nx_idx] = {nx_dis, nx_gol};
                hep.push({{-nx_dis,nx_gol},nx_idx});
            } else if(nx_dis == dist[nx_idx].first &&
                      nx_gol > dist[nx_idx].second) {
                dist[nx_idx] = {nx_dis, nx_gol};
                hep.push({{-nx_dis,nx_gol},nx_idx});
            }
        }
    }
    return dist[des].second;
}
int main() {
    ios_base::sync_with_stdio(false);
    long long frac = 1;
    pr[1] = true;
    for(int i = 1; i < Max; i++)
        if(!pr[i]) {
            frac*=i;
            primes.push_back(frac);
            for(int j = i + i; j < Max; j += i)
                pr[j] = true;
        }
    primes.push_back(1ll<<62);
    long long MinID = 1ll<<62;
    long long MaxID = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> id[i];
        id2idx[id[i]] = i;
        MinID = min(MinID, id[i]);
        MaxID = max(MaxID, id[i]);
    }
    for(int i = 0; i < m; i++) {
        long long id1,id2;
        cin >> id1 >> id2;
        int u = id2idx[id1];
        int v = id2idx[id2];
        long long x;
        cin >> x;
        d[u].emplace_back(x,v);
        d[v].emplace_back(x,u);
    }
    cout << dis(id2idx[MinID],id2idx[MaxID]);
    return 0;
}

