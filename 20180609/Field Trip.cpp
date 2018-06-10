#include <bits/stdc++.h>
using namespace std;
void solve(int ntest){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    int MX = 0;
    int MY = 0;
    int mY = 1<<30;
    int mX = 1<<30;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        MX = max(MX,x[i]);
        MY = max(MY,y[i]);
        mX = min(mX,x[i]);
        mY = min(mY,y[i]);
    }
    cout << "Case #" << ntest << ": ";
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans,max(abs(x[i] - (MX + mX)/2), abs(y[i] - (mY + MY)/2)));
    cout << ans;
    cout << endl;
}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t;i ++)
        solve(i);
}
