#include <bits/stdc++.h>
using namespace std;
long long MAX;
void solve(int nTest) {
    long long ans;
    long long n;
    cin >> n;
    ans = n-1;
    MAX = sqrt(n);
    for(int len = 2; len < 64; len++) {
        long long r = MAX;
        long long l = 2;
        long long best = -1;
        while(l <= r) {
            long long mid = (l+r)>>1;
            long long s = 0;
            long long t = 1;
            bool done = false;
            for(int i=1; i<=len && n - t >= s; i++){
                s += t;
                if(i==len) done = true;
                if((n-s)/mid < t) break;
                t *=mid;
            }
            if(s > n || !done) r = mid -1;
            else if (s < n) l = mid + 1;
            else {
                best = mid;
                break;
            }
        }
        if(best != -1) {
            cerr << n <<" "<<best << endl;
            ans = min(ans,best);
        }
    }


    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
main() {
   freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

