#include <bits/stdc++.h>
#define elif else if
using namespace std;
int ans;
int d[1<<20][30];
vector<string> S;
int n,m;
int all;
main() {
    ios_base::sync_with_stdio (false);
    ans=1<<30;
    cin>>n;
    S.resize(n);
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    all=(1<<n)-1;
    m=S[0].length();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        d[1<<i][j]=(S[i][j]=='1');
    for(int i=1;i<=all;i++){
        int tmp=((i&(-i))&all);
        for(int j=0;j<m;j++){
            d[i][j]=d[i-tmp][j]+d[tmp][j];
        }
    }
    for(int i=0;i<=all;i++){
        int na=__builtin_popcount(i),nb=n-na;
        int r=0;
        for(int j=0;j<m;j++){
            r+=min(na-d[i][j],d[i][j]);
            r+=min(nb-d[all-i][j],d[all-i][j]);
        }
        ans=min(ans,r);
    }
    cout<<ans<<endl;

}
