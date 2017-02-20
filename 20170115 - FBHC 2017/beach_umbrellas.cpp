#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int mul(int x,int v){
    if(v < 0) return 0;
    if(v == 0) return 1;
    int tmp = mul(x,v/2);
    if(v&1) return (1ll*tmp*x)%mod;
    else return (1ll*tmp*tmp)%mod;
}
vector<int> r;
int F[2222];
int muln[8000888];
int muln_1[8000888];

void run(int numtest){
    long long ans = 0;
    int n,m;
    int sum = 0;
    cin >> n >> m;
    r.resize(n);
    for(int i=0;i < n; i++){
        cin >> r[i];
        sum += 2*r[i];
    }
    muln[0]=mul(m,n);
    muln_1[0] = mul(m,n-1)
    for(int i=1; i <= sum; i++){
            muln[i] = (1ll*muln[i-1]*mul(m-i,n)) % mod;
            muln_1[i] = (1ll*muln_1[i-1]*mul(m-i,n-1)) % mod;
        }
    if(n == 1) ans = m;
    else{
        for(int i=0; i < n ; i++)
            for(int j=0; j < n; j++)
            if(i != j){
                if(m >= sum)
                    ans = (ans + 1ll*mul(m - sum + r[i] + r[j],n+1)*F[n-2])%mod;
            }
    }
    cout <<"Case #"<<numtest<<": "<<ans<<endl;
}
main(){
    freopen("beach_umbrellas.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    F[0] = 1;
    for(int i=1; i<=2000;i++)
        F[i] = (1ll*F[i-1]*i) %mod;
    cin >> t;
    for(int i=1;i <= t; i++)
        run(i);
}
