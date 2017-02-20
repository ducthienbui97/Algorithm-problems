#include <bits/stdc++.h>
using namespace std;
bool done[2222][2222];
double F[2222][2222];
double pro(int l,int r){
    if(done[l][r]) return F[l][r];
    done[l][r] = true;
    if(l == 0) F[l][r] = 0;
    else if(r == 0) F[l][r] = 1;
    else F[l][r] = 1.*l/(l+r)*pro(l-1,r)*(l-1>r)+1.*r/(l+r)*pro(l,r-1)*(l>r-1);
    return F[l][r];
}
main(){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        cout <<"Case #"<<i<<": "<<fixed<<setprecision(9)<<pro(a,b)<<endl;
    }

}
