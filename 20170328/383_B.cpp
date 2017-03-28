#include <bits/stdc++.h>
using namespace std;
int root[1011];
int DP[1011][1011];
int Sw[1011];
int Sb[1011];
int findroot(int u){
    if(root[u]!=u) root[u] = findroot(root[u]);
    return root[u];
}
bool cmp(int v,int u){
    return findroot(v) < findroot(u);
}
vector<int> W,B,T;
int first[1011];
int F(int lo,int wi){
    if(wi < 0) return -1000111000;
    if(lo < 0) return 0;
    if(DP[lo][wi] >= 0) return DP[lo][wi];
    DP[lo][wi] = F(lo-1,wi);
    int r = findroot(T[lo]);
    int u = T[lo];
    DP[lo][wi] = max(DP[lo][wi],F(first[r]-1,wi-W[u])+B[u]);
    DP[lo][wi] = max(DP[lo][wi],F(first[r]-1,wi-Sw[r])+Sb[r]);
    return DP[lo][wi];
}
main(){
    ios_base::sync_with_stdio(false);
    int n,m,w;
    cin >> n >>m >> w;
    W.resize(n);
    B.resize(n);
    T.resize(n);
    for(auto&u:W)
        cin >> u;
    for(auto&u:B)
        cin >> u;
    for(int i=0;i<n;i++){
        root[i]=i;
        T[i] = i;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        root[findroot(--x)] = root[findroot(--y)];
    }
    sort(T.begin(),T.end(),cmp);
    memset(first,0x3f,sizeof first);
    for(int i=0;i<T.size();i++){
        int r = findroot(T[i]);
        first[r] = min(first[r],i);
        Sw[r] += W[T[i]];
        Sb[r] += B[T[i]];
    }

    memset(DP,-1,sizeof DP);
    cout << F(n-1,w);
}
