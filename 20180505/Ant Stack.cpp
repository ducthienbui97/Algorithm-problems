#include <bits/stdc++.h>
using namespace std;
const int sz = 1e6;
long long sum[sz], ls[sz];
void solve(int ntest) {
    memset(sum,0x3f,sizeof sum);
    memset(ls,0x3f,sizeof ls);
    sum[0] = 0;
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long w;
        cin >> w;
        for(int i = ans; i >= 0; i--){
            if(sum[i] <= w*6){
                if(sum[i] + w < sum[i+1]){
                    sum[i + 1] = sum[i] + w;
                    ls[i + 1] = w;
                    if(i == ans)
                        ans ++;
                }
            }
        }
    }
    cout <<"Case #"<<ntest<<": "<< ans << endl;
}
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}

