#include <bits/stdc++.h>
using namespace std;
double DP[2][1111];
int ans[1111];
double eps = 1e-7;
int main(){
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    DP[0][0] = 1;
    for(int day = 1,solved = 1;solved <= 1000;day++){
        for(int i=1;i<=k;i++){
            DP[day&1][i] = (DP[1 - (day&1)][i]*i + DP[1 - (day&1)][i - 1]*(k-i+1))/k;
        }
        while(solved <= 1000 && DP[day&1][k]*2000 >= (solved - eps))
            ans[solved++] = day;
        DP[0][0] = 0;
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> k;
        cout << ans[k] <<endl;
    }
}
