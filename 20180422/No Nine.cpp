#include <bits/stdc++.h>
using namespace std;
long long F[20][9][2];
bool done[20][9][2];
string s;
long long calF(int n,int mol,int isSmaller) {
    //cout << " "<<n <<" "<<mol <<" "<<isSmaller << endl;
    if(n == s.size())
        if(mol!=0 && isSmaller)
            return 1;
        else
            return 0;
    if(done[n][mol][isSmaller])
        return F[n][mol][isSmaller];
    done[n][mol][isSmaller] = true;
    F[n][mol][isSmaller] = 0;
    int bar = 8;
    if(!isSmaller)
        bar = min(bar,s[n] - '0');
    //cout << bar << endl;
    for(int i = 0; i <= bar; i++)
        F[n][mol][isSmaller] += calF(n + 1, (mol+i)%9, isSmaller || i < s[n] - '0');
    return F[n][mol][isSmaller];
}
long long cal(long long H) {
    memset(done,0,sizeof done);
    s = to_string(H);
    return calF(0,0,0);
}
void solve(int ntest) {
    long long F,L;
    cin >> F >> L;
    cout << "Case #" << ntest <<": "<< cal(L) - cal(F) + 1 << endl;
}
main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i <= t; i ++)
        solve(i);
}
