#include <bits/stdc++.h>
using namespace std;
int F[3333][3333];
bool M[3333][3333];
void solve(int nTest) {
    memset(M,0,sizeof M);
    memset(F,0,sizeof F);
    int n,m,k;
    long long ans = 0;
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++){
        int x,y;
        cin >> x >> y;
        ++x,++y;
        M[x][y] = 1;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(!M[i][j])
            F[i][j] = min(F[i-1][j],min(F[i][j-1],F[i-1][j-1])) + 1;
        ans += F[i][j];
    }

    cout <<"Case #"<<nTest<<": "<<ans<<endl;
}
main() {
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)solve(i);
}



