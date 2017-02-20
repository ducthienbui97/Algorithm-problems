#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[5000], r[5000];
long long dp[5000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    rep(i, n) r[i] = a[i];
    sort(r, r+n);
    rep(i, n) rep(j, n) {
        dp[j] += abs(a[i]-r[j]);
        if(j>0) dp[j] = min(dp[j], dp[j-1]);
    }
    long long ans = 1LL<<60;
    rep(i, n) ans = min(ans, dp[i]);
    cout << ans << endl;
    return 0;
}