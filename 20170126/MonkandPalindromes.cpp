#include <bits/stdc++.h>
using namespace std;
vector<int> r;
int findroot(int p){
    if(r[p] == p) return r[p];
    return r[p] = findroot(r[p]);
}
const int base = 1e9+7;
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    r.resize(n);
    for(int i=0;i<n;i++){
        r[i] = i;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x>>y;
        for(int j=0;x+j<=y;j++){
            if(x != y){
                r[findroot(x+j-1)] = findroot(y-j-1);
            }
        }
    }
    long long ans = 1;
    for(int i=0;i<n;i++)
    if(i == findroot(i)){
        ans=10*ans%base;
    }
    cout << ans%base ;
}
