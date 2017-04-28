#include <bits/stdc++.h>
using namespace std;
long long F[5005];
void solve(int nTest) {
    long long ans = 0;
    int n,m;
    cin >> n >> m;
    F[0] = 1;
    for(int i=1;i<=n;i++)
        F[i] = F[i-1]*i%m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans = (ans + F[min(i,j)]*F[max(i,j) - min(i,j)]%m*F[n-max(i,j)]%m)%m;
    cout <<"Case #"<<nTest<<": "<<ans <<endl;
}
main() {
    freopen("D-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)solve(i);
}



