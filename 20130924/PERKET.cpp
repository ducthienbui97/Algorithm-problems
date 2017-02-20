#include <bits/stdc++.h>
#define elif else if
using namespace std;
int a[22],b[22];
int n;
int cal(int cc){
    int ch=1,ca=0;
    for(int i=0;i<n;i++)
    if(cc&(1<<i)){
        ch*=a[i];
        ca+=b[i];
    }
    return abs(ch-ca);
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    int ans=INT_MAX;
    for(int i=(1<<n)-1;i>0;i--)
        ans=min(ans,cal(i));
    cout<<ans;
}
