#include <bits/stdc++.h>
#define elif else if
using namespace std;
int ucln(int u,int v) {
    if(u>v) swap(u,v);
    if(!u) return v;
    return ucln(v%u,u);
    }
typedef pair<int,int> point;
#define X first
#define Y second
const int Maxn=1511;
map<point,int> d[Maxn];
point a[Maxn];
main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int cnt1=0,cnt2=0;
    int ans=0;
    for(int i=1; i<=n; i++)
        cin>>a[i].X>>a[i].Y;
    for(int i=1; i<=n; i++,cnt1=0,cnt2=0)
        for(int j=1; j<=n; j++)
            if(i!=j) {
                if(a[i].X==a[j].X) cnt1++,ans+=cnt2;
                elif(a[i].Y==a[j].Y) cnt2++,ans+=cnt1;
                else {
                    point t=point(a[j].X-a[i].X,a[j].Y-a[i].Y);
                    int k=ucln(abs(t.X),abs(t.Y));
                    t.X/=k;
                    t.Y/=k;
                    if(t.Y>0) {
                        t.X*=-1;
                        t.Y*=-1;
                        }
                    ans+=d[i][point(-t.Y,t.X)];
                    if(t.X<0) {
                        t.X*=-1;
                        t.Y*=-1;
                        }
                    d[i][t]++;
                    }
                }
    cout<<ans;

    }
