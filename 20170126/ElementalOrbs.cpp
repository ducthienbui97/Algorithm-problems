#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int f[2222];
int d[2222];
int e;
int b[2222];
int mule;
const int base = 1e9+7;
int mul(int x,int v){
    if(v==0) return 1;
    if(v&1){
        int t = mul(x,v-1);
        return 1ll*t*x%base;
    }else{
        int t = mul(x,v/2);
        return 1ll*t*t%base;
    }
}
int dp(int t){
    if(!t) return 1;
    if(d[t]>=0) return d[t];
    d[t] = 0;
    for(int i=1;i<=t;i++){
        d[t] = (1ll*dp(t-i)*(e-f[i])+d[t])%base;
    }
    d[t] = ((1ll*d[t]*(e-1))%base)*mule%base;
    return d[t];
}
void run(){
    memset(f,0,sizeof f);
    memset(d,-1,sizeof d);
    cin >> n >> e;
    for(int i=0;i<e;i++)
        cin >> b[i];
    for(int i=0;i<e;i++)
        f[b[i]+1] ++;
    for(int i=1;i<=n+1;i++){
        f[i] += f[i-1];
    }
    mule = mul(e,base-2);
    cout << (1ll*dp(n)*e)%base <<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    for(cin>>t;t>0;t--) run();
}
