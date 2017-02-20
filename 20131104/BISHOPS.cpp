#include <iostream>
#include <cstdio>
#include <cstring>
#define elif else if
#define int long long
using namespace std;
const int Mod=1e8;
int n,k;
int DP[200][200];
int dp(){
    if(n==1&&k==1) return 1;
    memset(DP,0,sizeof DP);
    DP[0][0]=1;
    DP[1][0]=1;
    DP[2][0]=1;
    DP[1][1]=2;
    DP[2][1]=4;
    DP[2][2]=2;
    for(int i=3;i<n;i++){
        DP[i][0]=1;
        DP[i][1]=DP[i-2][1]+2*i*DP[i-2][0];
        DP[i][1]%=Mod;
        for(int j=2;j<=k;j++){
            DP[i][j]=DP[i-2][j]+(i-j+1)*(2*DP[i-2][j-1]+(i-j+2)*DP[i-2][j-2]);
            DP[i][j]%=Mod;
        }
    }
    DP[n][0]=1;
    for(int i=1;i<=k;i++){
        DP[n][i]=DP[n-2][i]+(n-i+1)*DP[n-2][i-1];
        DP[n][i]%=Mod;
    }
    int ans=0;
    for(int i=0;i<=k;i++){
        ans+=DP[n][i]*DP[n-1][k-i];
        ans%=Mod;
    }
    return ans;
}

main() {
    freopen("BISHOPS.INP","r",stdin);
    freopen("BISHOPS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    while(cin>>n>>k) cout<<dp()%Mod<<endl;
}
