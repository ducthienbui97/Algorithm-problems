#include <bits/stdc++.h>
using namespace std;
vector<int> V;
main(){
    freopen("TRAINING.INP","r",stdin);
    freopen("TRAINING.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    int a,b;
    int ans=0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(!b){
            if(a>=k) ans++;
        }else{
            V.push_back((k-a-1)/b+1);
        }
    }
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++)
    if(m>=V[i]){
        ans++;
        m-=V[i];
    }
    printf("%d",ans);
}
