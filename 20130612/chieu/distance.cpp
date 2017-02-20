#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#define fi first
#define nd second
#define mp(a,b) make_pair(a,b)

using namespace std;
struct canh{
    int den,w;
};
int n,k,l,goc[100100],D[100100],ans=2000000000;
vector<canh> dinh[100100];
set<pair<int,int> > S;
void input(){
    scanf("%d %d %d\n",&n,&k,&l);
    int a,b,w;
    canh c;
    for(int i=0;i<k;i++) {
        D[i]=200000000;
        goc[i]=-1;
    }
    for(int i=0;i<n;i++){
        scanf("%d\n",&a);
        a--;
        S.insert(mp(0,a));
        D[a]=0;
        goc[a]=a;
    }
    for(int i=0;i<l;i++){
        scanf("%d %d %d\n",&a,&b,&w);
        a--;b--;
        c.w=w;
        c.den=b;
        dinh[a].push_back(c);
        c.den=a;
        dinh[b].push_back(c);
    }
}
void solve(){
    pair<int,int> u;
    canh v;
    set<pair<int,int> >::iterator IT;
    if (S.size()==n){
        while(S.size()>0){
            u=*S.begin();
            S.erase(S.begin());
            for(int i=0;i<dinh[u.nd].size();i++){
                v=dinh[u.nd][i];
                if (goc[v.den]==-1){
                    D[v.den]=D[u.nd]+v.w;
                    S.insert(mp(D[v.den],v.den));
                    goc[v.den]=goc[u.nd];
                } else {
                    if (goc[v.den]==goc[u.nd]){
                        if (D[v.den]>D[u.nd]+v.w){
                            S.erase(S.find(mp(D[v.den],v.den)));
                            D[v.den]=D[u.nd]+v.w;
                            S.insert(mp(D[v.den],v.den));
                        }
                    } else {
                        ans=min(ans,D[v.den]+D[u.nd]+v.w);
                    }
                }
            }
        }
        cout<<ans*3;
    } else {
        cout<<0;
    }
}
int main(){
   // freopen("distance.inp","r",stdin);
   // freopen("distance.out","w",stdout);
    input();
    solve();
    return 0;
}
