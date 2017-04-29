#include <bits/stdc++.h>
using namespace std;
int vs[22][22];
double pr[22][22];
double p,q;
double ans;
int n,m;
int X[4]={1,-1,0,0};
int Y[4]={0,0,1,-1};
void bt(int x,int y,int s,double cur){
    if(cur + s < ans) return;
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(!s){
        ans = max(cur,ans);
        return;
    }
    vs[x][y] ++;
    for(int i=0;i<4;i++)
        bt(x+X[i],y+Y[i],s-1,cur+pr[x][y]*pow(1-pr[x][y],vs[x][y]-1));
    vs[x][y]--;
}
void solve(int nTest) {
    int x,y,s;
    ans = 0;
    cin >> n >> m >>x >>y>>s;
    cin >> p >> q;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        char c;
        cin >> c;
        if(c=='A') pr[i][j] = p;
        else pr[i][j] = q;
    }
    for(int i=0;i<4;i++)
        bt(x+X[i],y+Y[i],s,0);
    cout <<"Case #"<<nTest<<": "<<fixed<<setprecision(15)<<ans<<endl;
}
main() {
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)solve(i);
}




