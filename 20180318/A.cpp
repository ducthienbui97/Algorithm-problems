#include <bits/stdc++.h>
using namespace std;
void solve(int t) {
    long long n;
    cin >> n;
    string s = to_string(n);
    long long up = 0;
    long long dw = 0;
    for(int i = 0; i < s.size(); i++) {
        if((s[i] - '0') % 2) {
            if(s[i] != '9') {
                up = up*10 + (s[i] + 1 - '0');
                for(int j = i + 1; j < s.size(); j++)
                    up = up*10;
            }else
                up = 1ll<<60;
            dw = dw *10 + (s[i] - 1 - '0');
            for(int j = i + 1; j < s.size(); j++)
                dw = dw*10 + 8;
            break;
        } else {
            up = up*10 + (s[i] - '0');
            dw = dw*10 + (s[i] - '0');
        }
    }
    cout <<"Case #" << t <<": "<< min(up - n, n - dw) << endl;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++)
        solve(i);
}
