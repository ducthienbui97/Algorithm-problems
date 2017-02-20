#include <bits/stdc++.h>
#define elif else if
using namespace std;
int A,B,D;
int F[1111][11111];
const int INF=1<<29;
struct pabulum{
    int t,w;
    bool operator <(const pabulum& X) const{
        return t*X.w<X.t*w;
    }
};
bool ok(int s,int l){
    return s-l<=A&&l<=B;
}
int sum[1111];
vector<pabulum> d;
main(){
    ios_base::sync_with_stdio(false);
    int n;
    memset(F,0x1f,sizeof F);
    cin>>n>>A>>B>>D;
    A=D-A;
    B=B-D;
    d.resize(n);
    for(int i=0;i<n;i++)
        cin>>d[i].t>>d[i].w;
    sort(d.begin(),d.end());
    int s=0;
    for(int i=0;i<n;i++){
        s+=d[i].t;
        sum[i]=s;
    }
    for(int i=0;i<=B;i++)
        if(ok(sum[0],i)) F[0][i]=i*d[0].w;
    for(int i=1;i<n;i++)
    for(int j=0;j<=B;j++)if(ok(sum[i],j)){
        if(j>=d[i].t) F[i][j]=min(F[i][j],F[i-1][j-d[i].t]+j*d[i].w);
        if(sum[i-1]>=j) F[i][j]=min(F[i][j],F[i-1][j]+(sum[i-1]-j)*d[i].w);
    }
    int ans=INF;
    for(int j=0;j<=B;j++)
    ans=min(ans,F[n-1][j]);
    cout<<ans<<endl;
}
