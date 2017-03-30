#include <bits/stdc++.h>
using namespace std;
int root[1000111];
int cnt[1000111];
int sf[1000111];
int findroot(int u){
    if(root[u]!=u) root[u] = findroot(root[u]);
    return root[u];
}
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    int pivot=1;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        root[i]=i;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >>y;
        if(x==y) sf[x]++;
        else cnt[x]++,cnt[y]++;
        root[findroot(x)] = root[findroot(y)];
        pivot = x;
    }

    long long ans = 0;
    for(int i=1;i<=n;i++) ans += sf[i];
    ans = ans*(ans-1)/2+ans*(m-ans);
    for(int i=1;i<=n;i++) ans += 1ll*cnt[i]*(cnt[i]-1)/2;
    for(int i=1;i<=n;i++)
    if(findroot(i) != findroot(pivot) && (sf[i] ||cnt[i]))
        ans = 0;
    cout << ans <<endl;

}
