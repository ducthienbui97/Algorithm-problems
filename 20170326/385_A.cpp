#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1011;
int root[Maxn];
vector<int> gg;
int d[Maxn];
int vs[Maxn];
int findroot(int u){
    if(u!=root[u]) root[u] = findroot(root[u]);
    return root[u];
}
main(){
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    gg.resize(k);
    for(int i=1;i<=n;i++)
        root[i] = i;
    for(int i=0;i<k;i++){
        cin >> gg[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        root[findroot(x)] = root[findroot(y)];
        d[x]++;
        d[y]++;
    }
    int Max = 0;
    int t;
    for(int g:gg){
        int c = root[findroot(g)];
        int cnt = 0;
        for(int i=1;i<=n;i++)
            if(root[findroot(i)] == c) vs[i] = 1, cnt++;
        if(cnt > Max){
            Max = cnt;
            t = g;
        }
    }
    for(int i=1;i<=n;i++)if(!vs[i]){
        root[findroot(i)] = root[findroot(t)];
    }
    int ans = 0;
    for(int g:gg){
        int c = root[findroot(g)];
        int cnt = 0;
        for(int i=1;i<=n;i++)
            if(root[findroot(i)] == c) cnt++;
        ans += cnt*(cnt-1)/2;
        cnt = 0;
        for(int i=1;i<=n;i++)
            if(root[findroot(i)] == c) cnt += d[i];
        ans -= cnt/2;

    }
    cout << ans <<endl;
}
