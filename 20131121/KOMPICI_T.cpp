#include <bits/stdc++.h>
#define elif else if
using namespace std;
long long x,ans;
int cnt[1<<10],n;
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        int t=0;
        while(x){
            t|=(1<<(x%10));
            x/=10;
        }
        cnt[t]++;
    }
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
        if(i&j) ans+=1ll*cnt[i]*(cnt[j]-(i==j));
    cout<<(ans>>1);
}
