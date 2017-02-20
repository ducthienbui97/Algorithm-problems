#include <bits/stdc++.h>
#define elif else if
using namespace std;
int F[3333][3333];
int A[3333],B[3333];
main(){
    ios_base::sync_with_stdio(false);
    int n,t,s;
    cin>>n>>t>>s;
    for(int i=1;i<=n;i++)
        cin>>A[i]>>B[i];
    for(int i=1;i<=t;i++)
    for(int j=1;j<=n;j++){
        F[i][j]=max(F[i][j-1],F[i-1][j]);
        if(i>=B[j]&&((s-i)*(s-(i-B[j])))>=0)
            F[i][j]=max(F[i][j],F[i-B[j]][j-1]+A[j]);
    }
    cout<<F[t][n];
}
