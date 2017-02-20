#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int c[1111];
int n,m;
bool ok(){
    int t=0;
    for(int i=0;i<=m+1;i++){
        t+=c[i];
        if(t<0) return false;
    }
    return true;
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>m>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=0;
    for(int i=0;i<n/2;i++){
        c[v[i]]++;
        c[v[i]-1]++;
        c[v[i<<1]-1]--;
        c[v[(i<<1)+1]-1]--;
       // cerr<<i<<" ";
        if(ok()) ans=i+1;
       // cerr<<endl;
    }
    printf("%d",ans);
}
