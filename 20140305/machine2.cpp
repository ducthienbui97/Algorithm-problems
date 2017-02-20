#include <bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
int F[111][111][111];
vector<pair<int,int> > farmer;
main(){
    ios_base::sync_with_stdio(false);
    memset(F,-1,sizeof F);
    int n;
    cin>>n;
    farmer.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>farmer[i].first>>farmer[i].second;
    sort(farmer.begin(),farmer.end());
    farmer[0].first=farmer[0].second=-1;
    //farmer[n+1].first=farmer[n+1].second=1<<30;
    F[0][0][0]=0;
    int ans=0;
    for(int i=0;i<=n;i++){
    for(int k=0;k<=i;k++)
    for(int l=0;l<=i;l++){
        if(i==n){
            ans=max(ans,F[i][k][l]);
            continue;
        }
        F[i+1][k][l]=max(F[i+1][k][l],F[i][k][l]);
        if(farmer[i+1].first>farmer[k].second) F[i+1][i+1][l]=max(F[i+1][i+1][l],F[i][k][l]+farmer[i+1].second-farmer[i+1].first+1);
        if(farmer[i+1].first>farmer[l].second) F[i+1][k][i+1]=max(F[i+1][k][i+1],F[i][k][l]+farmer[i+1].second-farmer[i+1].first+1);
    }
    }
    cout<<ans<<endl;

}
