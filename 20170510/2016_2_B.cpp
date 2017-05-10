#include <bits/stdc++.h>
using namespace std;
vector<double> v,p;
bool done[222][222];
double F[222][222];
double cal(int y,int n){
    if(y < 0 || n < 0) return 0;
    if(y== 0 && n== 0) return 1;
    if(done[y][n]) return F[y][n];
    int cur = y + n - 1;
    done[y][n] = true;
    F[y][n] = p[cur]*cal(y-1,n) + (1-p[cur])*cal(y,n-1);
    return F[y][n];
}
void solve(int nTest){
    int n,k;
    cin >> n >> k;
    v.resize(n);
    for(auto&c:v)
        cin >> c;
    sort(v.begin(),v.end());
    double ans = 0;
    for(int i=0;i<=k;i++){
        memset(done,0,sizeof done);
        p.clear();
        for(int j=0;j<i;j++)
            p.push_back(v[j]);
        for(int j=0;j+i<k;j++)
            p.push_back(v[n-1-j]);
        ans = max(ans,cal(k/2,k/2));
    }
    cout << "Case #"<<nTest<<": "<<fixed<<setprecision(15)<<ans<<endl;
}
main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

