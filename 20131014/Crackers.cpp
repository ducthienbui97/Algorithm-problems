#include <bits/stdc++.h>
#define elif else if
using namespace std;
int c[10011];
int a[10011];
main() {
    int ans=0,n,m;
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            a[j]|=(x<<i);
        }
    for(int i=0;i<(1<<n);i++){
        int tmp=0;
        for(int j=0;j<m;j++){
            int t=__builtin_popcount(a[j]^i);
            tmp+=max(t,n-t);
        }
        ans=max(ans,tmp);
    }
    cout<<ans;

}


