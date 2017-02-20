#include<bits/stdc++.h>
using namespace std;

long long f[19][10][2];

long long dp(long long n) {
    vector<int> a;
    for(long long x = n; x != 0; x /= 10) a.push_back(x % 10);
    reverse(a.begin(), a.end());
    memset(f, 0, sizeof f);
    int len = a.size();
    for(int i = 1; i <= a[0]; ++i) f[0][i][i < a[0]] = 1;
    for(int i = 0; i + 1 < len; ++i)
        for(int d = 0; d < 10; ++d)
            for(int grt = 0; grt < 2; ++grt) if(f[i][d][grt] != 0) {
                for(int nx = d-1; nx <= d+1; ++nx) {
                    if(nx < 0 || nx > 9) continue;
                    if(grt == 0 && nx > a[i+1]) continue;
                    f[i+1][nx][grt | (nx < a[i+1])] += f[i][d][grt];
                }
            }
    long long res = 0;
    for(int d = 0; d < 10; ++d) res += f[len-1][d][0] + f[len-1][d][1];
    return res;
}

long long stableCount(long long n) {
    long long res = 0;
    for(long long p = 10; p <= n; p *= 10) res += dp(p-1);
    return res + dp(n);
}

long long getnum(long long minn, long long maxx, long long pos) {
    long long l = minn, r = maxx;
    while(l < r) {
        long long mid = (l + r) / 2;
        if(stableCount(mid) - stableCount(minn-1) >= pos) r = mid;
        else l = mid+1;
    }
    return l;
}

int main() {
    long long a, b; cin >> a >> b;
    int q; cin >> q;
    long long nstable = stableCount(b-1) - stableCount(a);
    if(q == 1) cout << nstable << endl;
    else {
        if(nstable % 2 == 1) cout << getnum(a+1, b-1, (nstable+1)/2) << endl;
        else cout << getnum(a+1, b-1, nstable/2) << ' ' << getnum(a+1, b-1, nstable/2+1) << endl;
    }
    return 0;
}
