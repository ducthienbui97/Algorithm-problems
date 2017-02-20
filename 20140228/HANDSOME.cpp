#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Mod=1e9+7;
const int Max=400044;
int F[Max][5][5];
char S[11];
char C[Max];
int K[Max];
int P[Max];
bool non[5][5];
int mul(const int& a,const int& x){
    if(!x) return 1;
    int rep=mul(a,x>>1);
    rep=(1ll*rep*rep)%Mod;
    if(x&1) return (1ll*rep*a)%Mod;
    else return rep;
}
const int add(int &x,const int& y){if((x+=y)>=Mod) x-=Mod;}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>P[i];
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>S;
        non[S[0]-'0'][S[1]-'0']=true;
    }
    cin>>C;
    for(int i=0;i<n;i++)
        K[i+1]=C[i]-'0';
    K[0]=K[n+1]=4;
    for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++)
        F[0][i][j]=!non[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=4;j++)
            for(int l=1;l<4;l++)
                if(!non[l][j])
                for(int k=1;k<=4;k++)
                add(F[i][k][j],F[i-1][k][l]);
    set<int> ms;
    ms.insert(0);
    ms.insert(n+1);
    int ans=0,now=F[n][4][4];
    for(int i=1;i<=n;i++){
        set<int>::iterator it;
        it=ms.lower_bound(P[i]);
        int r=*it;
        int l=*(--it);
        now=(1ll*now*mul(F[r-l-1][K[l]][K[r]],Mod-2))%Mod;
        int tmp=0;
        for(int j=1;j<K[P[i]];j++)
            add(tmp,(1ll*F[P[i]-l-1][K[l]][j]*F[r-P[i]-1][j][K[r]])%Mod);
        add(ans,(1ll*tmp*now)%Mod);
        tmp=(1ll*F[P[i]-l-1][K[l]][K[P[i]]]*F[r-P[i]-1][K[P[i]]][K[r]])%Mod;
        now=(1ll*now*tmp)%Mod;
        ms.insert(P[i]);
    }
    add(ans,now);
    printf("%d",ans);
}
