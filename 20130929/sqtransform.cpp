#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define elif else if
#define input "sqtransform.inp"
#define output "sqtransform.out"
using namespace std;
inline void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
int n,S;
int F[11][11111];
int a[11];
main() {
#ifndef HYQ
    openfile();
#endif
    ios_base::sync_with_stdio(false);
    cin>>n>>S;
    memset(F,0x3f,sizeof F);
    int Max=F[0][0];
    F[0][0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=S;j++)
            for(int l=0;l*l<=j;l++){
            F[i][j]=min(F[i][j],F[i-1][j-l*l]+(a[i]-l)*(a[i]-l));
        }
   if(Max<=F[n][S]) printf("-1\n");
   else printf("%d\n",F[n][S]);
    }
