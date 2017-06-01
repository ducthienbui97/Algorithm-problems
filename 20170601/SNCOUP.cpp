#include <bits/stdc++.h>
using namespace std;
const int inf = 1<<30;
int F[111000][2][2];
void solve() {
    memset(F,0x3f,sizeof F);
    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    bool ho = false;
    for(int i=0;i<n;i++){
        if(s1[i] == '*' && s2[i] == '*') ho = true;
    }
    int ans = 0;
    if(!ho)
        for(int i=0;i<n;i++)
            if(s1[i] == '*' || s2[i] == '*') ans ++;
    if(ans > 0) ans --;
    if(ho) ans = inf;
    if(s1[0] == '*' && s2[0] == '*') F[0][1][1] = 0;
    else if(s1[0] == '*') F[0][1][0] = 0;
    else if(s2[0] == '*') F[0][0][1] = 0;
    else F[0][0][0] = 0;
    for(int i=1;i<n;i++){
        if(s1[i] == '*' && s2[i] == '*'){
            F[i][1][1] = F[i-1][0][0];
            F[i][1][1] = min(F[i][1][1],F[i-1][1][0] + 1);
            F[i][1][1] = min(F[i][1][1],F[i-1][1][1] + 1);
            F[i][1][1] = min(F[i][1][1],F[i-1][0][1] + 1);
        }else if(s1[i] == '*'){
            F[i][1][1] = F[i-1][0][1];
            F[i][1][0] = F[i-1][0][0];
            F[i][1][0] = min(F[i][1][0],F[i-1][1][0] + 1);
            F[i][1][0] = min(F[i][1][0],F[i-1][1][1] + 1);
        }else if(s2[i] == '*'){
            F[i][1][1] = F[i-1][1][0];
            F[i][0][1] = F[i-1][0][0];
            F[i][0][1] = min(F[i][0][1],F[i-1][0][1] + 1);
            F[i][0][1] = min(F[i][0][1],F[i-1][1][1] + 1);
        }else{
            F[i][0][0] = F[i-1][0][0];
            F[i][0][0] = min(F[i][0][0],F[i-1][1][0] + 1);
            F[i][0][0] = min(F[i][0][0],F[i-1][1][1] + 1);
            F[i][0][0] = min(F[i][0][0],F[i-1][0][1] + 1);
            F[i][1][0] = F[i-1][1][0];
            F[i][0][1] = F[i-1][0][1];
            F[i][1][1] = F[i-1][1][1];
        }
        //cout << i <<" "<<F[i][0][0] <<" "<<F[i][1][1] <<" "<<F[i][0][1] <<" "<<F[i][1][0]<<endl;
    }
    //cout << ans <<'\n';
    cout << min(ans,min(min(F[n-1][0][0],F[n-1][1][0]),min(F[n-1][1][1],F[n-1][0][1])) + 1) <<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solve();
}
