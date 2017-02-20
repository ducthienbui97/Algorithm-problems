#include <bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int ans=0,now=0,x;
    set<int> ms;
    for(int i=0;i<n;i++){
        cin>>x;
        now=((now+x)%m+m)%m;
        ans=max(ans,max(now,(now+m-((!ms.empty()&&ms.upper_bound(now)!=ms.end())?(*ms.upper_bound(now)):(now+m)))));
        ms.insert(now);
    }
    cout<<ans;
}
