#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6+20;
int cnt[20][Maxn];
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=0;j<20;j++)
            cnt[j][i] = cnt[j][i-1] + ((x>>j)&1);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int r = x2 - x1 + 1;
        int c = y2 - y1 + 1;
        long long ans = 0;
        for(int j=0;j<20;j++){
            int cntR = cnt[j][x2] - cnt[j][x1-1];
            int cntC = cnt[j][y2] - cnt[j][y1-1];
            ans += (1ll << j)*(1ll*(c-cntC)*cntR+1ll*(r-cntR)*cntC);
        }
        cout << ans <<endl;
    }
}
