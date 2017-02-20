#include <iostream>
#include <cstdio>
#include <cstring>
#define elif else if
using namespace std;
int F[1111][1111];
int t;
char c[1111];
main() {
     freopen("Squared.inp","r",stdin);
    freopen("Squared.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    cin>>c+1;
    int ans=0;
    for(int i=1;i<n-ans;i++){
        for(int j=1;j<=n;j++)
            F[j][i]=0;
        for(int j=1;j<=i;j++)
            for(int k=i+1;k<=n;k++)
            if(c[j]==c[k]) F[j][k]=F[j-1][k-1]+1;
            else F[j][k]=max(F[j-1][k],F[j][k-1]);
        ans=max(ans,F[i][n]);
    }
    printf("%d",n-(ans<<1));
    }
