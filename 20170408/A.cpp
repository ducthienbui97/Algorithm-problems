#include <bits/stdc++.h>
using namespace std;
int flipcnt[10011];
int k;
string s;
void solve(int numTest) {
    memset(flipcnt,0,sizeof flipcnt);
    int ans = 0;
    cin >> s >> k;
    for(int i=0; i<s.size(); i++) {
        if(i) flipcnt[i] +=flipcnt[i-1];
        bool  flip = flipcnt[i]&1;
        if((flip&&s[i]=='+')||(!flip&&s[i]=='-')) {
            if(i+k <= s.size()) {
                flipcnt[i]+=1;
                flipcnt[i+k]-=1;
                ans++;

            }else{
                ans = -1;
                break;
            }
        }
    }
    cout << "Case #" << numTest << ": "<< (ans>=0?to_string(ans):"IMPOSSIBLE")<<"\n";
}
main() {
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}
