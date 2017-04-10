#include <bits/stdc++.h>
using namespace std;
bool dp[555][555][555];
int a[555];
set<int> ans;
main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[0][0][0] = true;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int l=0;l<=k;l++)
            dp[i][j][l] = dp[i-1][j][l]|(l>=a[i]?dp[i-1][j][l-a[i]]:0)|(j>=a[i]&&l>=a[i]?dp[i-1][j-a[i]][l-a[i]]:0);
    for(int i=0;i<=k;i++)
        if(dp[n][i][k]) ans.insert(i);
    cout << ans.size()<<endl;;
    for(int v:ans) cout << v <<" ";
}
