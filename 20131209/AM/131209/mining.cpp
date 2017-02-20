#include <bits/stdc++.h>
#define elif else if
using namespace std;
template<class T> void getmax(T& x,T y){if(x<y) x=y;}
int f[222][222];
int sum[222][222];
int n,m;
main() {
     ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>f[i][j];
        sum[i][j]=sum[i][j-1]+f[i][j];
    }
    int ans=-(1<<30);
    for(int i=1;i<=m;i++)
    for(int j=0;j+i<=m;j++){
        int t=-(1<<30);
        for(int ii=1;ii<=n;ii++){
            t=max(t+sum[ii][i+j]-sum[ii][j],sum[ii][i+j]-sum[ii][j]);
            ans=max(t,ans);
        }
    }
    cout<<ans<<endl;
}
