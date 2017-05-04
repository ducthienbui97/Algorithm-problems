#include <bits/stdc++.h>
using namespace std;
long long MAX;
void solve(int nTest) {
    long long ans;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<s.size();i++)
        cnt += s[i] == 'B';
    long long l,r;
    cin >> l >> r;
    l --;
    ans = (r/s.size() - l/s.size())*cnt;
    l%=s.size();
    r%=s.size();
    for(int i=0;i<l;i++)
        ans -= s[i] == 'B';
    for(int i=0;i<r;i++)
        ans += s[i] == 'B';
    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
main() {
   freopen("A-small-practice.in","r",stdin);
   freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}


