#include <bits/stdc++.h>
#define elif else if
using namespace std;
int t,n,m;
int a[111],b[111],c[111],d[111];
bool check(int T1){
    int T2=t-T1;
    int L1=0,L2=0;
    for(int i=1;i<=n;i++)
        L1+=(T1-a[i])/b[i];
    for(int j=1;j<=m;j++)
        L2+=(T2-c[j])/d[j];
    return L1<=L2;
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>t>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    cin>>m;
    for(int j=1;j<=m;j++)
        cin>>c[j]>>d[j];
    int l=0;
    int r=t;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
}
