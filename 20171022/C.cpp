#include <bits/stdc++.h>
using namespace std;
int ans,n;
int F[44];
bool cut[44];
void try_cut(int cnt,int cur){
    if(cnt == n){
        ans = max(ans,cur);
        return;
    }
    for(int i = 1; i < n; i++)
    if(!cut[i]){
        int l = i - 1;
        int r = i;
        for(int j = i - 1; j > 0 && !cut[j]; j--)
            if(F[j] < F[l]) l = j;
        for(int j = i; j < n && !cut[j]; j++)
            if(F[j] < F[r]) r = j;
        cut[i] = true;
        try_cut(cnt + 1, cur + min(F[l],F[r]));
        cut[i] = false;
    }
}
void solve(int n_test) {
    int tmp;
    cin >> tmp >> n;
    ans = 0;
    for(int i = 0; i < n; i++)
        cin >> F[i];
    try_cut(1,0);

    cout << "Case #" << n_test << ": " << ans << "\n";
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}

