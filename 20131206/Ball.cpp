#include <bits/stdc++.h>
#define elif else if
using namespace std;
int a[3],w,n,all;
int lg[1<<10];
long long f[3][11][11],F[11][11][11];
bool d[10][1<<10][1<<10];
long long ans[10][1<<10][1<<10];
long long dp(int now,int t1,int t2){
    if(now==n) return 0;
    if(d[now][t1][t2]) return  ans[now][t1][t2];
    d[now][t1][t2]=true;
    int m1= (~t1)&all;
    int m2= (~t2)&all;
    for(int i=m1;i>0;){
        int tmp1=i&(-i);
        for(int j=m2;j>0;){
            int tmp2=j&(-j);
            ans[now][t1][t2]=max(ans[now][t1][t2],dp(now+1,t1|tmp1,t2|tmp2)+
                                F[now][lg[tmp1]][lg[tmp2]]+f[0][now][lg[tmp1]]+f[1][now][lg[tmp2]]+f[2][lg[tmp1]][lg[tmp2]]
                                 );
            j-=tmp2;

        }
        i-=tmp1;
    }
    return ans[now][t1][t2];
}
main() {
    ios_base::sync_with_stdio (false);
    cin>>n>>a[0]>>a[1]>>a[2]>>w;
    all=(1<<n)-1;
    for(int i=0;i<n;i++)
        lg[1<<i]=i;
    for(int i=0; i<3; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++) {
                cin>>f[i][j][k];
                f[i][j][k]*=a[i];
                }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++) {
                cin>>F[i][j][k];
                F[i][j][k]*=w;
                }
    cout<<dp(0,0,0);
    }
