#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    long long n,m,ans;
    cin >> n >> m;
    ans = min(n,m/2);
    n-=ans;
    m-=2*ans;
    cout << ans + m/4 <<endl;
}
