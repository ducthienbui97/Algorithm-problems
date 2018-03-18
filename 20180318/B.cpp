#include <bits/stdc++.h>
using namespace std;
void solve(int t) {
    long long total = 0;
    int n, k;
    double F;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        total += v[i];
    }
    sort(v.begin(),v.end());
    F = 1.*total/n;
    int cur = 0;
    for(int i = 1; i <= k; i++){
        while(F > v[cur]){
            total -= v[cur];
            cur++;
        }
        F = (F*cur + total)/n;
    }
    cout <<"Case #" <<t <<": " <<setprecision(10) << fixed << F << endl;
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
