#include <bits/stdc++.h>
#define elif else if
using namespace std;
inline bool in(long long val,long long l,long long r) {
    return l<=val&&val<=r;
    }
main() {
    freopen("TRIPLET.IN","r",stdin);
    freopen("TRIPLET.OUT","w",stdout);
        ios_base::sync_with_stdio(false);

    long long minA,minB,minC,maxA,maxB,maxC;
    cin>>minA>>maxA>>minB>>maxB>>minC>>maxC;
    long long cnt=0;
    if(maxA*maxB<minC||minA*minB>maxC) {
        puts("0");
        return 0;
        }

    if(maxA*maxB<=maxC&&minA*minB>=minC) {
        cout<<(maxA-minA+1)*(maxB-minB+1);
        return 0;
        }
     minA=max(minA,minC/maxB);
     maxA=min(maxA,maxC/minB);
    for(long long i=minA;i<=maxA;i++){
        for(long long j=max(minB,minC/i);j*i<=maxC&&j<=maxB;j++)
            if(in(j*i,minC,maxC)) cnt++;
    }
    cout<<cnt<<endl;
    }
