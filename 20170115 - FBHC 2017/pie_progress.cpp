#include <bits/stdc++.h>
using namespace std;
int F[333][333];
int c[333][333];

void run(int numtest) {
    int n,m;
    cin >> n >> m;
    for(int i=1 ; i <= n; i++) {
        for(int j=1; j <= m; j++)
            cin >> c[i][j];
        sort(c[i] + 1,c[i] + m + 1);
        for(int j=2; j<=m;j++)
            c[i][j] += c[i][j-1];
    }
    memset(F,0x3f,sizeof F);
    F[0][0] = 0;
    for(int i=1; i <= n; i++){
        for(int j = i; j <= n; j++){
            F[i][j] = F[i-1][j];
            for(int k = 1; k <= m && j - k + 1 >= i; k++)
                F[i][j] = min(F[i][j],F[i-1][j-k]   + c[i][k] + k*k);
        }

    }
    cout << "Case #"<<numtest<<": "<<F[n][n] <<endl;
}
main() {
    freopen("pie_progress.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i <= t; i ++)
        run(i);
}
