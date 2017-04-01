#include <bits/stdc++.h>
using namespace std;
vector<int> cnt;
vector<int> emp,fil;
main() {
    ios_base::sync_with_stdio(false);
    int n,s,wro;
    int x,ans = 1<<30;
    cin >> n >> s;
    cnt.resize(n);
    emp.resize(n);
    fil.resize(n);
    for(int i=1; i<=n; i++) {
        cin >> x;
        if(s==i) wro = (x != 0);
        else cnt[x]++;
    }

    emp[0] = cnt[0] == 0;
    fil[0] = cnt[0];
    for(int i=1;i<n;i++)
        fil[i] = fil[i-1]+cnt[i],emp[i] = emp[i-1] + (cnt[i] == 0);
    for(int i=1;i<n;i++){
        int OUT = n - 1 - (fil[i] - fil[0]);
        int EMP = emp[i] - emp[0];
        ans = min(ans,max(OUT,EMP));
    }

    cout << (n!=1)*ans+wro <<endl;

}
