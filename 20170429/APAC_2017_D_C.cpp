#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long DP[4444];
map<string,int> voc;
void solve(int nTest) {
    int v,s;
    voc.clear();
    cin >> v >> s;
    for(int i=0; i < v; i++) {
        string tmp;
        cin >> tmp;
        sort(tmp.begin(),tmp.end());
        voc[tmp]++;
    }
    cout << "Case #"<<nTest<<":";
    for(int i=0; i<s; i++) {
        string S;
        cin >> S;
        DP[0] = 1;
        for(int i=1; i<=S.size(); i++) {
            DP[i] = 0;
            for(int j=1; j<=20&&i-j>=0; j++) {
                string tmp = S.substr(i-j,j);
                sort(tmp.begin(),tmp.end());
                DP[i] = (DP[i]+DP[i-j]*voc[tmp]%mod)%mod;
            }

        }
        cout <<' '<< DP[S.size()]%mod;
    }
    cout <<'\n';
    cerr <<nTest<<endl;

}
main() {
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

