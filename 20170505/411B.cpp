#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
main(){
    ios_base::sync_with_stdio(false);
    string s;
    int cur = 0;
    int ans = 0;
    cin >> s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            ans += cur;
            cur = 2*cur;
        }else{
            cur += 1;
        }
        cur%=mod;
        ans%=mod;
    }
    cout << ans <<endl;
}

