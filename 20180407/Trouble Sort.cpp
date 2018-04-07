#include <bits/stdc++.h>
using namespace std;

void solve(int test){
    int n;
    cin >> n;
    vector<int> v[2];
    for(int i =0; i < n;i++){
        int x;
        cin >> x;
        v[i&1].push_back(x);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    vector<int> x(n);
    for(int i = n - 1; i>=0; i--){
        x[i] = v[i&1].back();
        v[i&1].pop_back();
    }
    int ans = 0;
    for(int i=1;i<n;i++)
        if(x[i] < x[i-1]){
            ans = i;
            break;
        }
    cout <<"Case #"<<test<<": "<< (ans?to_string(ans-1):"OK") << endl;
}
main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdtout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i <= t;i++)
        solve(i);
}
