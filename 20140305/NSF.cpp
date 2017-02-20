#include <bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
const int Max=5e5+20;
int C[Max];
void init(){
    for(int i=2;i<Max;i++){
        for(int j=i+i;j<Max;j+=i)
            C[j]+=(-C[i]+1);
    }
}
int cal(int T){
    int S=0;
    for(int i=2;i*i<=T;i++){
        int tmp=T/(i*i);
        S+=tmp*(1-C[i]);
    }
    return S;
}
main() {
    ios_base::sync_with_stdio(false);
    init();
    int l=2;
    int r=250000000000ll;
    int ans=0;
    int x;
    cin>>x;
    while(l<=r){
        int mid=(l+r)>>1;
        if(cal(mid)>=x) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
}
