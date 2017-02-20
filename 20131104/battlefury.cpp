#include <bits/stdc++.h>
#define elif else if
using namespace std;
int n,p,q;
vector<int> dam;
vector<int> d;
bool ok(int m){
    int cnt=0;
    int t=p-q;
    for(int i=0;i<n;i++)
        d[i]=dam[i];
    for(int i=0;i<n;i++)
        if(d[i]/q>=m) d[i]-=q*m;
        else d[i]=0;
    if(t)
    for(int i=0;i<n;i++){
        if(!(d[i]%t)) cnt+=d[i]/t;
        else cnt+=(d[i]/t)+1;
        d[i]=0;
        if(cnt>m) return false;
    }
    for(int i=0;i<n;i++)
        if(d[i]>0) return false;
    return true;
}
main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>p>>q;
    dam.resize(n);
    d.resize(n);
    for(int i=0;i<n;i++)
        cin>>dam[i];
    ok(4);
    int l=0;
    int r=1000000000;
    int ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d",ans);
}
