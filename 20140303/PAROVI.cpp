#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Max=55000;
const int Mod=1e9+7;
int F[Max][10][2][2];
int G[Max][10][2][2];
string A,B;
int n;
vector<int> a,b;
int cal(int x,int t,bool sm,bool bg) {
    if(x>=n) return F[x][t][sm][bg]=1;
    if(F[x][t][sm][bg]) return F[x][t][sm][bg];
    for(int i=(!bg?a[x]:0); i<=(!sm?b[x]:9); i++) {
        if((F[x][t][sm][bg]+=cal(x+1,i,sm||i<b[x],bg||i>a[x]))>=Mod) F[x][t][sm][bg]-=Mod;
        }
    return F[x][t][sm][bg];
    }
main() {
    ios_base::sync_with_stdio(false);
    cin>>A;
    for(int i=0; i<A.size(); i++)
        a.push_back(A[i]-'0');
    cin>>B;
    for(int i=0; i<B.size(); i++)
        b.push_back(B[i]-'0');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    n=max(a.size(),b.size());
    a.resize(n);
    b.resize(n);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    cal(0,0,0,0);
    G[0][0][0][0]=1;
    for(int i=0; i<n; i++) {
        for(int j1=0; j1<10; j1++)
            for(int k1=0; k1<2; k1++)
                for(int k2=0; k2<2; k2++)
                    for(int j2=(!k2?a[i]:0); j2<=(!k1?b[i]:9); j2++) {
                        if((G[i+1][j2][k1||j2<b[i]][k2||j2>a[i]]+=G[i][j1][k1][k2])>=Mod) G[i+1][j2][k1||j2<b[i]][k2||j2>a[i]]-=Mod;
                        }
        }
    int ans=0;
    for(int i=1; i<=n; i++) {
        for(int j1=0; j1<10; j1++)
            for(int k1=0; k1<2; k1++)
                for(int k2=0; k2<2; k2++)
                    if(F[i][j1][k1][k2]&&G[i][j1][k1][k2]) {
                        int tmp1=(1ll*G[i][j1][k1][k2]*F[i][j1][k1][k2])%Mod;
                        for(int j2=0; j2<j1; j2++)
                            for(int k3=0; k3<2; k3++)
                                for(int k4=0; k4<2; k4++)
                                    if(F[i][j2][k3][k4]&&G[i][j2][k3][k4]){
                                    int tmp2=(1ll*G[i][j2][k3][k4]*F[i][j2][k3][k4])%Mod;
                                    if((ans+=((1ll*(j1-j2)*tmp1*tmp2)%Mod))>=Mod) ans-=Mod;
                                    }
                        }
        }
    if((ans<<=1)>=Mod) ans-=Mod;
    printf("%d",ans);
    }
