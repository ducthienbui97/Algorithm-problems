#include <bits/stdc++.h>
using namespace std;
const int inf = 1<<29;
int hd,ad,hk,ak,b,d;
int F[111][111][111][111];
int ans(int Hme,int Ame,int Hk,int Ak){
    if(Hk <= 0) return 0;
    if(Hme <= 0) return inf;
    if(Ame > Hk) return 1;
    if(F[Hme][Ame][Hk][Ak]) return F[Hme][Ame][Hk][Ak];
    F[Hme][Ame][Hk][Ak] = inf;
    if(d)
        F[Hme][Ame][Hk][Ak] = min(F[Hme][Ame][Hk][Ak],ans(Hme-max((Ak-d),0),Ame,Hk,max(Ak-d,0))+1);
    F[Hme][Ame][Hk][Ak] = min(F[Hme][Ame][Hk][Ak],ans(hd-Ak,Ame,Hk,Ak)+1);
    if(b)
        F[Hme][Ame][Hk][Ak] = min(F[Hme][Ame][Hk][Ak],ans(Hme-Ak,Ame+b,Hk,Ak)+1);
    F[Hme][Ame][Hk][Ak] = min(F[Hme][Ame][Hk][Ak],ans(Hme-Ak,Ame,Hk-Ame,Ak)+1);
    return F[Hme][Ame][Hk][Ak];
}
void solve(int nTest){
    memset(F,0,sizeof F);
    cin >> hd >> ad >>hk >> ak >>b >>d;
    int ANS = ans(hd,ad,hk,ak);
    string rep = "IMPOSSIBLE";
    if(ANS<inf) rep = to_string(ANS);
    cout << "Case #"<<nTest<<": "<<rep<<endl;
}
main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

