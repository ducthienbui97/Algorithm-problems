#include <bits/stdc++.h>
using namespace std;
long long dp[21][10][2];
long long Find(long long maxx){
    memset(dp,0,sizeof dp);
    string s = to_string(maxx);
    reverse(s.begin(),s.end());
    s.push_back('0');
    reverse(s.begin(),s.end());
    dp[0][0][0] = 1;
    for(int dg=1;dg<s.size();dg++){
        for(int nw=0;nw<=9;nw++){
            for(int ls=0;ls<=nw;ls++){
                dp[dg][nw][1] += dp[dg-1][ls][1]+(nw < s[dg]-'0')*dp[dg-1][ls][0];
                dp[dg][nw][0] += dp[dg-1][ls][0]*(nw == s[dg]-'0');
            }
       }
    }
    long long ans = 0;
    for(int i=0;i<=9;i++)
        ans+=dp[s.size()-1][i][0]+dp[s.size()-1][i][1];
    return ans;
}
void solve(int numTest) {
    long long l,r;
    long long ans;
    l = 0;
    cin >> r;
    long long val = Find(r);
    while(l<=r){
        long long mid = (l+r)>>1;
        if(Find(mid) == val){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid +1;
        }
    }
    cout <<"Case #"<<numTest<<": "<< ans <<endl;
}
main() {
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

