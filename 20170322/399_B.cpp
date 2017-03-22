#include <bits/stdc++.h>
using namespace std;
long long cnt(long long x){
    if(x <= 1) return 1;
    return 2ll*cnt(x>>1)+ 1;
}
long long cal(long long x,long long n){
    if(n <= 0) return 0;
    if(x <= 1) return x;
    if(cnt(x>>1) >= n) return cal(x>>1,n);
    else return (x>>1) + (x&1) + cal(x>>1,n-cnt(x>>1)-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    long long n;
    long long l,r;
    cin >> n >> l >> r;
    cout << cal(n,r) - cal(n,l-1) <<endl;
}
