#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long dis[111][111];
double tim[111][111];
long long maxDis[111];
int sped[111];
void solve(int nTest) {
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> maxDis[i]>>sped[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            cin >> dis[i][j];
            if(dis[i][j] < 0) dis[i][j] = i!=j ? inf:0;
        }
    for(int tmp = 0; tmp<n; tmp++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            if(dis[i][tmp]+dis[tmp][j] < dis[i][j])
                dis[i][j] = dis[i][tmp] + dis[tmp][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dis[i][j] <= maxDis[i]){
                tim[i][j] = 1.*dis[i][j]/sped[i];
            }
            else{
                tim[i][j] = inf;
            }
    for(int tmp = 0; tmp<n; tmp++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            if(tim[i][tmp]+tim[tmp][j] < tim[i][j]){
                tim[i][j] = tim[i][tmp] + tim[tmp][j];
            }
    cout << "Case #"<<nTest<<":";
    for(int i=0;i<q;i++){
        int u,v;
        cin >> u >> v;
        cout <<' '<<fixed <<setprecision(9)<<tim[--u][--v];
    }
    cout <<'\n';
}
main() {
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

