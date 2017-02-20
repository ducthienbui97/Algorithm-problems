#include <bits/stdc++.h>
using namespace std;
struct faction {
    int a,b;
    bool operator < (const faction& other) const {
        return a*other.b < b*other.a;
        }
    bool operator == (const faction& other) const {
        return a*other.b == b*other.a;
        }
    };
vector<faction> vf;
void solve() {
    int n;
    cin >> n;
    vf.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> vf[i].b >> vf[i].a;
        int gcd = __gcd(vf[i].b,vf[i].a);
        vf[i].b /= gcd;
        vf[i].a /= gcd;
        }
    sort(vf.begin(),vf.end());
    for(int i = n - 1; i >= 0; i--)
        if(vf[i].b == 0)
            n--;
        else if(i > 0 && vf[i]==vf[i-1])
            n--;
    cout << n << '\n';
    }
main() {
    int t;
    for(cin >> t; t > 0; t--)
        solve();
    }
/*
3
4
0 2
1 2
2 4
3 5
6
0 1
0 1
0 2
2 0
3 0
1 0
3
1 2
2 4
4 8
*/
