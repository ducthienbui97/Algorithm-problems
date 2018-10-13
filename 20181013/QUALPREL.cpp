#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    k--;
    vector<int> s(n);
    for(auto&u:s)
        cin >> u;
    sort(s.begin(), s.end());
    reverse(s.begin(),s.end());
    while(k + 1 < s.size() && s[k + 1] >= s[k])
        k++;
    cout << k + 1 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}
