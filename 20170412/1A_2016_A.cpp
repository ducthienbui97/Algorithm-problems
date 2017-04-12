#include <bits/stdc++.h>
using namespace std;
void solve(int nTest){
    string ans;
    string s;
    cin >> s;
    for(char c:s){
        ans = max(ans + c,c+ans);
    }
    cout <<"Case #"<<nTest<<": "<<ans<<endl;;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
