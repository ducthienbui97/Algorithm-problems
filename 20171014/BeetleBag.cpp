#include <bits/stdc++.h>

using namespace std;
int F[555];
void solve() {
    int n,c;
    cin >> c >> n;
    memset(F,-1,sizeof F);
    int ans = 0;
    F[0] = 0;
    for(int i = 0; i < n; i++) {
        int w,f;
        cin >> w >> f;
        for(int j = c; j >= w; j--) {
            if(F[j - w] >= 0)
                F[j] = max(F[j], F[j - w] + f);
            ans = max(ans, F[j]);
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}


