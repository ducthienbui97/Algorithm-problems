#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5+20;
const int base = 1e9+7;
long long F[sz];
void solve() {
    map<int,int> mp;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    long long ans = 1;
    bool isEven = true;
    for(auto&p:mp) {
        int s = p.second;
        if (!isEven)  {
            ans = ans * s % base;
            s--;
        }
        isEven = true;
        if(s%2) {
            ans = ans * s % base;
            isEven = false;
            s--;
        }

        ans = ans * F[s] % base;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    F[0] = 1;
    F[1] = 1;
    F[2] = 1;
    for(int i = 3; i < sz; i++) {
        if(i % 2 == 0) {
            F[i] = F[i - 1];
        } else {
            F[i] = (F[i - 1] + (i - 1)*F[i - 2])%base;
        }
    }

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}


