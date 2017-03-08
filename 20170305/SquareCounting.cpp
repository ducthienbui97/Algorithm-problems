#include <bits/stdc++.h>
using namespace std;
const long long base = 1e9+7;
long long mul(long long x,long long y){
    if(y==0) return 1;
    if(y&1){
        return mul(x,y-1)*x%base;
    }else{
        long long tmp = mul(x,y/2);
        return tmp*tmp%base;
    }
}
void sol(int test){
    long long r,c;
    cin >> r >>c;
    if(r>c) swap(r,c);
    long long dif = c - r;
    long long ans = 0;
    long long rc = r*c%base;
    ans = ((dif * r)%base*(r-1))%base*mul(2,base-2)%base + ((((r-1)*(r))%base*(2*(r-1) + 1))%base*mul(6,base-2))%base;
    for(int i = 2; i < r; i++){
        ans = (ans + (r-i)*(c-i)%base*(i-1))%base;
    }
    printf("Case #%d: %lld\n",test,ans);
}
main(){
    freopen("A-small-practice.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
}
