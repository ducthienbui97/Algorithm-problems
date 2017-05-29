#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    string s;
    int k,b,m;
    cin >> s >> k >> b >> m;
    int pw = 1;
    for(int i=0;i<k;i++)
        pw = (pw*b)%m;
    int hs = 0;
    int ans = 0;
    for(int i=0;i<k;i++){
        hs = (hs*b + (s[i]-'0'))%m;
    }
    ans += hs;
    for(int i=k;i < s.size(); i++){
        hs = ((hs*b - (s[i-k]-'0')*pw + (s[i]-'0'))%m + m)%m;
        ans += hs;
    }
    cout << ans <<endl;
}
