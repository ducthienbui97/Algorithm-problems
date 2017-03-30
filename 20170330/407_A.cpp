#include <bits/stdc++.h>
using namespace std;
int a[111000],n;
int b[111000];
main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++)
    if(i&1) b[i] = abs(a[i]-a[i+1]);
    else b[i] = -abs(a[i]-a[i+1]);
    long long s = 0;
    long long ans =0;
    for(int i=1;i<n;i++){
        s+=b[i];
        ans = max(ans,s);
        s = max(s,0ll);
    }
    s = 0;
    for(int i=1;i<n;i++){
        s-=b[i];
        ans = max(ans,s);
        s = max(s,0ll);
    }
    cout << ans <<endl;
}
