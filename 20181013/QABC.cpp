#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n;
    vector<int> s(n), v(n);
    for(auto&u:s)
        cin >> u;
    for(auto&u:v)
        cin >> u;
    for(int i = n - 3; i >= 0; i--){
        int diff = max((v[i + 2] - s[i + 2])/3, 0);
        s[i + 2] += 3*diff;
        s[i + 1] += 2*diff;
        s[i] += diff;
    }
    cout << ((s == v)?"TAK":"NIE") << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}


