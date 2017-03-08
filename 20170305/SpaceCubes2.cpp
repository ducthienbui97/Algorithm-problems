#include <bits/stdc++.h>
using namespace std;
const int inf = 1<<30;
vector<int> x,y,z,r;
int MinX,MinY,MinZ,MaxR;
bool F[2222];
void sol(int test) {
    int n;
    cin >> n;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    r.resize(n);
    int ans = inf;
    for(int i = 0 ; i < n; i++)
        cin >> x[i] >> y[i] >> z[i] >> r[i];
    MinX = 0;
    MinY = 0;
    MinZ = 0;
    MaxR = 0;
    for(int i=1; i<n; i++) {
        if(x[MinX] - r[MinX] > x[i] - r[i]) MinX = i;
        if(y[MinY] - r[MinY] > y[i] - r[i]) MinY = i;
        if(z[MinZ] - r[MinZ] > z[i] - r[i]) MinZ = i;
        if(r[MaxR] < r[i]) MaxR = i;
    }
    int ll = 2*r[MaxR];
    int rr = inf;
    while(ll<=rr) {
        int mid = (ll+rr) >> 1;
        bool ok = false;
        for(int idx=0; idx<n && !ok; idx++) {
            int X0 = -inf,Y0 = -inf,Z0 = -inf,x0 = inf,y0 = inf,z0 = inf;
            int X1 = x[MinX] - r[MinX] + mid,Y1 = y[idx] - r[idx]+ mid,Z1 = z[MinZ] - r[MinZ] + mid,x1 = x[MinX] - r[MinX],y1 = y[idx] - r[idx],z1 = z[MinZ] - r[MinZ];
            bool hv = true;
            for(int i=0; i<n; i++)
                if(x[i] + r[i] > X1 || x[i] - r[i] < x1 || y[i] + r[i] > Y1 || y[i] - r[i] < y1 || z[i]+r[i] > Z1 || z[i] - r[i] < z1) {
                    X0 = max(x[i]+r[i],X0);
                    Y0 = max(y[i]+r[i],Y0);
                    Z0 = max(z[i]+r[i],Z0);
                    x0 = min(x[i]-r[i],x0);
                    y0 = min(y[i]-r[i],y0);
                    z0 = min(z[i]-r[i],z0);
                    hv = false;
                }
            ok = max(max(X0-x0,Y0-y0),Z0-z0) <= mid || hv;
        }

        for(int idx=0; idx<n && !ok; idx++) {
            int X0 = -inf,Y0 = -inf,Z0 = -inf,x0 = inf,y0 = inf,z0 = inf;
            int X1 = x[idx] - r[idx] + mid,Y1 = y[MinY] - r[MinY]+ mid,Z1 = z[MinZ] - r[MinZ] + mid,x1 = x[idx] - r[idx],y1 = y[MinY] - r[MinY],z1 = z[MinZ] - r[MinZ];
            bool hv = true;
            for(int i=0; i<n; i++)
                if(x[i] + r[i] > X1 || x[i] - r[i] < x1 || y[i] + r[i] > Y1 || y[i] - r[i] < y1 || z[i]+r[i] > Z1 || z[i] - r[i] < z1) {
                    X0 = max(x[i]+r[i],X0);
                    Y0 = max(y[i]+r[i],Y0);
                    Z0 = max(z[i]+r[i],Z0);
                    x0 = min(x[i]-r[i],x0);
                    y0 = min(y[i]-r[i],y0);
                    z0 = min(z[i]-r[i],z0);
                    hv =false;
                }
            ok = max(max(X0-x0,Y0-y0),Z0-z0) <= mid || hv;
        }


        for(int idx=0; idx<n && !ok; idx++) {
            int X0 = -inf,Y0 = -inf,Z0 = -inf,x0 = inf,y0 = inf,z0 = inf;
            int X1 = x[MinX] - r[MinX] + mid,Y1 = y[MinY] - r[MinY]+ mid,Z1 = z[idx] - r[idx] + mid,x1 = x[MinX] - r[MinX],y1 = y[MinY] - r[MinY],z1 = z[idx] - r[idx];
            bool hv = true;
            for(int i=0; i<n; i++)
                if(x[i] + r[i] > X1 || x[i] - r[i] < x1 || y[i] + r[i] > Y1 || y[i] - r[i] < y1 || z[i]+r[i] > Z1 || z[i] - r[i] < z1) {
                    X0 = max(x[i]+r[i],X0);
                    Y0 = max(y[i]+r[i],Y0);
                    Z0 = max(z[i]+r[i],Z0);
                    x0 = min(x[i]-r[i],x0);
                    y0 = min(y[i]-r[i],y0);
                    z0 = min(z[i]-r[i],z0);
                    hv = false;
                }
            ok = max(max(X0-x0,Y0-y0),Z0-z0) <= mid || hv;
        }

        if(ok) ans = mid,rr = mid -1;
        else ll = mid +1;
    }
    printf("Case #%d: %d\n",test,ans);
}
main() {
    freopen("C-small-practice.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) sol(i);
}
