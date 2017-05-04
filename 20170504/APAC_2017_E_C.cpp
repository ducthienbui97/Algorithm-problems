#include <bits/stdc++.h>
using namespace std;
void solve(int nTest){
    long long ans = 0;
    int n,d;
    cin >> n >> d;
    for(int first = d;first <= n; first += d)
        for(int used = first;used <= n; used += first){
            int remain = n - used;
            int p1 = remain/(first+1);
            int p2 = remain%(first+1);
            if(p1 < p2) continue;
            p1 -= p2;
            ans ++;
            ans += p1/(first+2);
        }
    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
