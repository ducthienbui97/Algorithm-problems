#include <bits/stdc++.h>
using namespace std;
char C[111][111];
set<int> ok[111][111][111];
int green[111][111][111];
int n,m,k;
int ANS[111][111][111];
int F[111];
bool Green(int r,int cl,int cr) {
    if(cl < 0 || cr >= m) return false;
    if(cr < cl) return true;
    if(green[r][cl][cr] > 0) return green[r][cl][cr];
    return green[r][cl][cr] = C[r][cl] =='#' && C[r][cr]=='#' && Green(r,cl+1,cr-1);
}
void solve(int nTest) {
    memset(green,-1,sizeof green);
    memset(ANS,0,sizeof ANS);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> C[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        for(int lv=0;lv<n;lv++)
        ok[lv][i][j].clear();
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            int l = j,r = j;
            for(int lv = 0; i + lv < n; lv++,l--,r++) {
                //cerr << lv <<" "<<i <<" "<<j <<endl;
                if(Green(i+lv,l,r)) {
                    for(int it = l; it <= r; it++)
                        ok[lv][i+lv][it].insert(j);
                } else break;
            }
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int lv=0; i - lv >= 0; lv++){
                if(!ok[lv][i][j].empty()) ANS[0][i][j] = max(ANS[0][i][j], F[lv+1]);
            }
    for(int cr=1; cr<k; cr++)
        for(int i=cr; i<n; i++)
            for(int j=0; j<m; j++)
                for(int lv=0; i-lv >= cr; lv++){
                    //cout << i <<" "<<j <<" "<<lv<<endl;
                    for(int j2:ok[lv][i][j])
                        ANS[cr][i][j] = max(ANS[cr][i][j],ANS[cr-1][i-lv-1][j2]+F[lv+1]);
                }
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans = max(ans, ANS[k-1][i][j]);
    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
int main() {
    for(int i=1;i<111;i++)
        F[i] = F[i-1]+2*i-1;
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

