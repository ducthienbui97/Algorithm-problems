#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > pii;
int A[1111][1111];
int F[1111][1111];
void solve() {
    memset(A,0,sizeof(A));
    int n,m,k;
    cin >> n >> m >> k ;
    set<pii> ms;
    for(int i = 1 ; i <= n; i++)
        for(int j = 1 ; j <= m ; j ++) {
            cin >> A[i][j];
            }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)if(A[i][j]) {
        F[i][j] = A[i-1][j]+A[i][j-1]+A[i+1][j]+A[i][j+1];
            ms.insert(pii(F[i][j],make_pair(i,j)));
            }
    for(; k > 0; k--) {
        pii cur = *ms.begin();
        ms.erase(cur);
        int i = cur.second.first;
        int j = cur.second.second;
        cout << i <<' '<<j<<'\n';
        A[i][j] = 0;
        if(A[i-1][j]==1) {
            ms.erase(pii(F[i-1][j],make_pair(i-1,j)));
            F[i-1][j] --;
            ms.insert(pii(F[i-1][j],make_pair(i-1,j)));
            }
        if(A[i][j-1]==1) {
            ms.erase(pii(F[i][j-1],make_pair(i,j-1)));
            F[i][j-1] --;
            ms.insert(pii(F[i][j-1],make_pair(i,j-1)));
            }
        if(A[i+1][j]==1) {
            ms.erase(pii(F[i+1][j],make_pair(i+1,j)));
            F[i+1][j] --;
            ms.insert(pii(F[i+1][j],make_pair(i+1,j)));
            }
        if(A[i][j+1]==1) {
            ms.erase(pii(F[i][j+1],make_pair(i,j+1)));
            F[i][j+1] --;
            ms.insert(pii(F[i][j+1],make_pair(i,j+1)));

            }
        }
    }
main() {
    ios_base::sync_with_stdio(false);
    int t;
    for(cin >> t; t > 0; t--)
        solve();
    }
    /*
    2
4 5 4
0 0 0 0 0
1 1 1 1 1
0 1 0 1 0
0 1 0 1 0
4 5 6
0 0 0 0 0
1 1 1 1 1
0 1 0 1 0
0 1 0 1 0
*/

