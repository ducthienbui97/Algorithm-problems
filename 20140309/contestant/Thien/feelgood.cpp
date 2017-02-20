#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Max=1e5+20;
int a[Max];
long long s[Max];
int l[Max],r[Max];
int n;
stack<int> d;
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        while(!d.empty()&&a[d.top()]>=a[i]) d.pop();
        if(d.empty()) l[i]=0;
        else l[i]=d.top();
        d.push(i);
    }
    while(!d.empty()) d.pop();
    for(int i=n;i>0;i--){
        while(!d.empty()&&a[d.top()]>=a[i]) d.pop();
        if(d.empty()) r[i]=n+1;
        else r[i]=d.top();
        d.push(i);
    }
    long long ans=-(1ll<<60);
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]*(s[r[i]-1]-s[l[i]]));
    }
    cout<<ans;
}
