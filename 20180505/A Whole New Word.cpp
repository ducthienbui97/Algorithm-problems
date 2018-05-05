#include <bits/stdc++.h>
using namespace std;
int direct[11][26][26];
int hs[11][26];
void solve(int ntest) {
    int n,l;
    cin >> n >> l;
    string s;
    string ans = "-";
    while(n-->0) {
        cin >> s;
        hs[0][s[0]-'A'] = ntest;
        for(int i = 1; i < l; i++) {
            direct[i][s[i-1]-'A'][s[i]-'A'] = ntest;
            hs[i][s[i]-'A'] = ntest;
        }
    }
    bool done = false;
    for(int i = 1; i < l && !done; i++)
        for(int j = 0; j < 26 && !done; j++)
            if(hs[i-1][j] == ntest)
                for(int k = 0; k < 26 && !done; k++)
                    if(hs[i][k] == ntest && direct[i][j][k] != ntest) {
                        ans = s;
                        ans[i - 1] = j + 'A';
                        ans[i] = k + 'A';
                        done = true;
                    }
    cout <<"Case #"<<ntest<<": "<< ans << endl;
}
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}
