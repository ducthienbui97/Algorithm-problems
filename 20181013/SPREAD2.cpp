#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin >> n;
    vector<int> s(n), sum(n);
    int current_sum = 0;
    for(auto&u:s)
        cin >> u;
    for(int i = 0; i < n; i++){
        current_sum = min(current_sum + s[i], n);
        sum[i] = current_sum;
    }
    int day = 0;
    int known = 1;
    while(known < n){
        day ++;
        known += sum[known - 1];
    }
    cout << day << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}

