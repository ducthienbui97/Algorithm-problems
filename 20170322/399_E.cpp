#include <bits/stdc++.h>
using namespace std;
map<pair<int,long long>,int> F;
int grundy(int t,long long st){
    if(t == 0) return 0;
    pair<int,long long> p = make_pair(t,st);
    if(F.find(p) != F.end()) return F[p];
    set<int> all;
    for(int i=1;i<=t;i++)
    if((1ll<<(i-1))&st){
        int to = t - i;
        all.insert(grundy(to,(st-(1ll<<(i-1)))&((1ll<<to)-1)));
    }
    int v = 0;
    while(all.find(v) != all.end()) v++;
    return F[p] = v;

}
int G[66];
main(){
    ios_base::sync_with_stdio(false);
    int n;
    for(int i=1;i<=60;i++) G[i] = grundy(i,(1ll<<i)-1);
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        ans^=G[x];
    }
    cout << (ans?"NO":"YES") <<endl;
}
