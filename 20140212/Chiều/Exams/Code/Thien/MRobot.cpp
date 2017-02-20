#include <iostream>
#include <cstdio>
#define elif else if
using namespace std;
int F_1[2000111];
int F_2[2000111];
const int Mod=1e9+7;
int mu(int a,int x) {
    if(x==1)  return a;
    if(!x) return 1;
    int tmp=mu(a,x>>1);
    int rep=(1ll*tmp*tmp)%Mod;
    if(x&1) {
        return (1ll*rep*a)%Mod;
        }
    else return rep;
    }
int doit(int cnt,int n,int m) {
    n--;
    m--;
    if(!n||!m) return 1;
    return (1ll*F_1[n+m]*((1ll*mu(F_1[n],Mod-2)*mu(F_1[m],Mod-2)%Mod)))%Mod;
}

main() {
    freopen("MRobot.inp","r",stdin);
    freopen("MRobot.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int n,m;
    F_1[1]=F_2[1]=1;
    for(int i=2;i<=2000000;i++){
         F_1[i]=(1ll*F_1[i-1]*i)%Mod;
    }
    for(int i=1; i<=t; i++) {
        cin>>n>>m;
        printf("%d\n",doit(i,n,m));
        }
    }
