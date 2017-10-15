#include <bits/stdc++.h>
using namespace std;
int F[222][222];
int a[222][222];
int n,m;
bool test(int val) {
    F[1][1] = val;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(i!=1 || j!=1) {
                F[i][j] = max(F[i-1][j],F[i][j-1]) + a[i][j];
                if(F[i][j] <= 0)
                    F[i][j] = -(1<<30);
            }
    return F[n][m] > 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    memset(F, 0b10111011, sizeof F);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    int low = 1;
    int hig = 1<<29;
    int ans = 1<<29;
    while(low <= hig) {
        int mid = (low + hig)/2;
        if(test(mid)) {
            ans = mid;
            hig = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

