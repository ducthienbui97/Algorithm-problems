#include <bits/stdc++.h>
using namespace std;
int q[55][55];
int require[55];
int idx[55];
void solve(int nTest) {
    int n,p,ans = 0;
    cin >> n >> p;
    for(int i=1; i<=n; i++) {
        cin >>require[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=p; j++)
            cin >> q[i][j];
        idx[i] = 1;
        sort(q[i]+1,q[i]+p+1);
    }
    for(int i=1; i<=p; i++) {
        idx[1] = i;
        int up = (10*q[1][i])/(9*require[1]);
        int lw = (10*q[1][i]-1)/(11*require[1])+1;
        if(lw > up) continue;
        for(int j=1; j<=n; j++) {
            int tmp_up = (10*q[j][idx[j]])/(9*require[j]);
            int tmp_lw = (10*q[j][idx[j]]-1)/(11*require[j])+1;
            while(tmp_up < lw||tmp_lw > tmp_up) {
                idx[j]++;
                if(idx[j] > p){
                    cout << "Case #"<<nTest<<": "<<ans<<endl;
                    return;
                }
                tmp_up = (10*q[j][idx[j]])/(9*require[j]);
                tmp_lw = (10*q[j][idx[j]]-1)/(11*require[j])+1;
            }
            up = min(up,tmp_up);
            lw = max(lw,tmp_lw);
        }
        if(up >= lw){
            ans ++;
            for(int j=1;j<=n;j++)
                idx[j]++;
        }
    }
    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
main() {
   // freopen("B-large.in","r",stdin);
   // freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}
