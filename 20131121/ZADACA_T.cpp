#include <bits/stdc++.h>
#define elif else if
using namespace std;
vector<int> A,B;
int n,m;
const int Mod=1e9;
bool bigger;
long long ans;
int ucln(int u,int v){
    if(u>v) swap(u,v);
    if(!u) return v;
    return ucln(v%u,u);
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    ans=1;
    A.resize(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    cin>>m;
    B.resize(m);
    for(int i=0;i<m;i++)
        cin>>B[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t=ucln(A[i],B[j]);
            ans*=t;
            if(ans>=Mod) ans%=Mod,bigger=true;
            A[i]/=t;
            B[j]/=t;
        }
    }
    if(bigger) printf("%09lld",ans);
    else printf("%lld",ans);
}
