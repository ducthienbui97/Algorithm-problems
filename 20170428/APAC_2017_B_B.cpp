#include <bits/stdc++.h>
using namespace std;
long long cn1[100011];
long long cn2[100011];
const long long Mod = 1e9+7;
long long pow(long long v,long long x,long long m) {
    if(x==0) return 1;
    if(x==1) return v%m;
    long long tmp;
    if(x&1) return pow(v,x-1,m)*v%m;
    else tmp = pow(v,x/2,m);
    return tmp*tmp%m;
}
void solve(long long nTest) {
    memset(cn1,0,sizeof cn1);
    memset(cn2,0,sizeof cn2);
    long long n;
    long long a,b,k;
    cin >> a >> b >> n >> k;
    long long ans = 0;
    for(long long i=1; i<=k; i++)if(i<=n) {
            long long num = ((n-i)/k + 1);
            long long r1 = pow(i,a,k)%k;
            cn1[r1] = (cn1[r1] + num)%Mod;
            long long r2 = pow(i,b,k)%k;
            cn2[r2] = (cn2[r2] + num)%Mod;
            if((r1+r2)%k==0)
                ans = ((ans - num)%Mod+ Mod)%Mod;
        }
    for(long long i=0; i<k; i++)
        ans = (ans + cn1[i]*cn2[(k-i)%k])%Mod;
    cout <<"Case #"<<nTest<<": "<<ans<<endl;
}
main() {
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    long long t;
    cin >> t;
    for(long long i=1; i<=t; i++)solve(i);
}

