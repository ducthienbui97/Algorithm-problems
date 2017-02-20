#include <bits/stdc++.h>
#include "alice.h"
const int Maxn=1e6+20;
using namespace std;
bool pr[Maxn];
int n;
void era(){
    pr[1]=true;
    for(int i=1;i<Maxn;i++)
    if(!pr[i]){
        for(long long j=i+i;j<Maxn;j+=i)
        pr[j]=true;
    }
}
int power(int x,int a){
    if(!a) return 1;
    if(a==1) return x;
    int y=power(x,a>>1);
    if(a&1) return y*y*x;
    return y*y;
}
int ffind(int x){
    int l=2,r=log(n)/log(x);
    int rep=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(is_divisible_by(power(x,mid))){
                rep=mid;
                l=mid+1;
        }
        else r=mid-1;
    }
    return rep;
}
vector<int> lis;
int main(){
    era();
    n=get_n();
    int m=1;
    for(int i=1;i<=n;i++)
        if(!pr[i] && 1ll*m*i<=n && is_divisible_by(i)){
            m*=power(i,ffind(i));
        }
    guess(m);
    return 0;
}
