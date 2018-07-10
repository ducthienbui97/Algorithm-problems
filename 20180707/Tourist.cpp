#include <bits/stdc++.h>
using namespace std;
void solve(int ntest){
    int n,k;
    long long v;
    cin >> n >> k >> v;
    vector<string> s(n);
    for(auto&ss:s)
        cin >> ss;
    int t = (v-1)*k%n;
    set<int> ms;
    for(int i=0;i<k;i++)
        ms.insert((t+i)%n);
    cout << "Case #" << ntest <<":";
    for(int i:ms)
        cout <<' ' << s[i];
    cout << endl;
}
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}
