#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5+20;
int nxt[Maxn];
bool vs[Maxn];
int root[Maxn];
int findroot(int t){
    if(root[t] != t) root[t] = findroot(root[t]);
    return root[t];
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> nxt[i];
        root[i] = i;
    }
    for(int i=1;i<=n;i++){
        root[findroot(i)] = root[findroot(nxt[i])];
    }
    int r = 0;
    for(int i=1;i<=n;i++) if(i == nxt[i]){
        r = i;
    }
    int ans = 0;
    if(!r) r = findroot(1),ans++,nxt[r] = r;
    for(int i=1;i<=n;i++){
        int rr = findroot(i);
        if(rr!=r){
            root[rr] = r;
            nxt[rr] = r;
            ans ++;
        }
    }
    cout << ans <<endl;
    for(int i=1;i<=n;i++)
        cout << nxt[i] << ' ';
}
