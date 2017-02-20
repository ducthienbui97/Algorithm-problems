#include <bits/stdc++.h>
using namespace std;
const int base = 1e9+7;
const int mx = 1e5+20;
vector<int> d[mx];
int n;
int F[mx][2];
int p[mx];
void dp(int u){
    if(d[u].size()==1&&p[u]>=0){
        F[u][0]=1;
        F[u][1]=0;
        return;
    }
    int pro[2]={1,1};
    for(int i=0;i<d[u].size();i++){
        int v = d[u][i];
        if(v==p[u]) continue;
        p[v] = u;
        dp(v);
        pro[0]=(1ll*pro[0]*(F[v][0]+F[v][1]))%base;
        pro[1]=(1ll*pro[1]*F[v][1])%base;
    }
    F[u][0] = pro[1];
    F[u][1] = 2*pro[0]%base;
    cout <<u <<" "<<F[u][0]<<" "<<F[u][1]<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        --x;--y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    fill(p,p+n,-1);
    dp(0);
    cout << F[0][1];
}
