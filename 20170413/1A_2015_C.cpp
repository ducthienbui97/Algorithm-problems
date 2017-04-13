#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<long long,long long> point;
int ans[3111];
point P[3111];
long long crossProduct(point x,point y,point z){
    return (y.X-x.X)*(z.Y-x.Y)-(y.Y-x.Y)*(z.X-x.X);
}
void solve(int nTest){
    memset(ans,0x3f,sizeof ans);
    int n,m;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> P[i].X >> P[i].Y;
    }
    if(n<=3)
    for(int i=1;i<=n;i++)
        ans[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++){
            int l1 = 0;
            int l2 = 0;
            for(int k=1;k<=n;k++){
                long long tmp = crossProduct(P[i],P[j],P[k]);
                if(tmp > 0) l1++;
                else if(tmp < 0) l2++;
            }
            ans[i] = min(ans[i],min(l1,l2));
            ans[j] = min(ans[j],min(l1,l2));
        }

    printf("Case #%d:\n",nTest);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    cerr << nTest<<endl;
}
main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

