#include <bits/stdc++.h>
using namespace std;

main(){
    freopen("TDEPTH.INP","r",stdin);
    freopen("TDEPTH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    long long n;
    cin>>n;
    if(!n){
        printf("0\n1 2\n");
        return 0;
    }
    long long tmp=0;
    int t=0;
    for(;tmp<n;){
        t++;
        tmp+=(1ll<<t);
    }
    printf("%d\n",t);
    long long tmp1=tmp - (1ll<<t);
    bool klq=true;
    if(n>tmp1+(1ll<<(t-1))){
        tmp1+=1ll<<(t-1);
        klq=false;
    }

    long long lo = ((n - tmp1)<<1) - klq;
    printf("%lld %lld",tmp+lo,tmp+lo+(1ll<<t));
}


