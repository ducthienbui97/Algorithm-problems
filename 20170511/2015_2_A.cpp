#include <bits/stdc++.h>
using namespace std;
char c[111][111];
bool ok[111][111][4];
string mr = "<>^v";
void solve(int nTest){
    int n,m;
    memset(ok,0,sizeof ok);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> (&c[i][1]);
    cout << "Case #"<<nTest<<": ";
    for(int i=1;i<=n;i++){
        int j = 1;
        while(j <= m && c[i][j] == '.') j++;
        if(j<=m) ok[i][j][0] = true;
        j = m;
        while(j > 0 && c[i][j] == '.') j--;
        if(j > 0) ok[i][j][1] = true;
    }
    for(int j=1;j<=m;j++){
        int i = 1;
        while(i <= n && c[i][j] == '.') i++;
        if(i<=n) ok[i][j][2] = true;
        i = n;
        while(i > 0 && c[i][j] == '.') i--;
        if(i > 0) ok[i][j][3] = true;
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(ok[i][j][0] && ok[i][j][1] && ok[i][j][2] && ok[i][j][3]){
                cout << "IMPOSSIBLE\n";
                return;
            }
            for(int d=0;d<4;d++)
                if(c[i][j] == mr[d] && ok[i][j][d])
                ans ++;
        }
    cout << ans<<endl;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
