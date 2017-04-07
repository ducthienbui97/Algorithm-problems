#include <bits/stdc++.h>
using namespace std;
const int Maxn = 111;
int F[Maxn][3];
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        for(int j=0;j<3;j++) F[i][j] = F[i-1][j];
        F[i][0] = max(F[i][0],max(F[i][1],F[i][2]));
        if(t == 1|| t==3)
            F[i][1] = max(F[i][1],max(F[i-1][2],F[i-1][0])+1);
        if(t == 2|| t==3)
            F[i][2] = max(F[i][2],max(F[i-1][1],F[i-1][0])+1);
    }
    cout << n - max(F[n][0],max(F[n][1],F[n][2]));

}
