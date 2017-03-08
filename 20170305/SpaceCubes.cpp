#include <bits/stdc++.h>
using namespace std;
const int inf = 1<<30;
void sol(int test){
    int n;
    cin >> n;
    vector<int> x,y,z,r;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    r.resize(n);
    int ans = inf;
    for(int i = 0 ;i < n; i++)
        cin >> x[i] >> y[i] >> z[i] >> r[i];
    for(int st=0;st<(1<<n);st++){
        int X0 = -inf,Y0 = -inf,Z0 = -inf,x0 = inf,y0 = inf,z0 = inf;
        int X1 = -inf,Y1 = -inf,Z1 = -inf,x1 = inf,y1 = inf,z1 = inf;
        for(int i=0;i<n;i++)
        if((st>>i)&1){
            X1 = max(x[i]+r[i],X1);
            Y1 = max(y[i]+r[i],Y1);
            Z1 = max(z[i]+r[i],Z1);
            x1 = min(x[i]-r[i],x1);
            y1 = min(y[i]-r[i],y1);
            z1 = min(z[i]-r[i],z1);
        }else{
            X0 = max(x[i]+r[i],X0);
            Y0 = max(y[i]+r[i],Y0);
            Z0 = max(z[i]+r[i],Z0);
            x0 = min(x[i]-r[i],x0);
            y0 = min(y[i]-r[i],y0);
            z0 = min(z[i]-r[i],z0);
        }
        int t1 = max(max(X1-x1,Y1-y1),Z1-z1);
        int t0 = max(max(X0-x0,Y0-y0),Z0-z0);
        ans = min(ans,max(t1,t0));
    }
    printf("Case #%d: %d\n",test,ans);
}
main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
}
