#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1011;
const int Maxm = 10011;
int n,m;
int st,fn, L;
bool done;
struct edge{
    int u,v,w,l;
} e[Maxm];
int trace[Maxn];
long long dist[Maxn];
vector<int> d[Maxn];
void dijk(){
    memset(dist,0x7f,sizeof dist);
    priority_queue<pair<long long,int>,vector<pair<long long,int> > ,greater<pair<long long,int> > > pr;
    dist[st] = 0;
    pr.push(make_pair(dist[st],st));
    while(!pr.empty()){
        long long ds = pr.top().first;
        int u = pr.top().second;
        pr.pop();
        if(ds > dist[u]) continue;
        for(int i:d[u]){
            int v;
            if(u==e[i].u) v = e[i].v;
            else v = e[i].u;
            if(dist[v] > dist[u] + e[i].w){
                dist[v] = dist[u] + e[i].w;
                pr.push(make_pair(dist[v],v));
                trace[v] = i;
            }
        }
    }
}
bool optimize(){
    dijk();
    if(dist[fn] == L) return false;
    if(dist[fn] > L){
        done = true;
        return false;
    }
    int cur = fn;
    int ls = -1;
    while(cur != st){
        int ed  = trace[cur];
        if(!e[ed].l){
            ls = ed;
            break;
        }
        else{
            if(cur == e[ed].u) cur = e[ed].v;
            else cur = e[ed].u;
        }
    }
    if(ls < 0){
       done = true;
       return false;
    }
    e[ls].w += L - dist[fn];
    e[ls].l = 1;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> L >> st >>fn;
    for(int i=0;i<m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].l = (e[i].w > 0);
        if(!e[i].l) e[i].w = 1;
        d[e[i].u].push_back(i);
        d[e[i].v].push_back(i);
    }
    while(optimize());
    if(!done){
        cout << "YES\n";
        for(int i=0;i<m;i++){
            cout << e[i].u <<' '<<e[i].v<<' ' << e[i].w <<'\n';
        }
    }
    else{
        cout << "NO\n";
    }
}
