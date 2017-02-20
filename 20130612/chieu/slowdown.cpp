#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
int n,P[100100],cha[100100],F[100100];
vector<int> dinh[100100];
int BIT[100100];
void input(){
    int a,b;
    scanf("%d\n",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d\n",&a,&b);
        a--;b--;
        dinh[a].push_back(b);
        dinh[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d\n",&a);
        a--;
        P[a]=i;  // con bo i o canh dong a
    }
    for(int i=0;i<=n;i++) BIT[i]=0;
}
void updateBIT(int u,int gt){
    for(u=u;u<=n;u+=u&(-u)) BIT[u]+=gt;
}
int getBIT(int u){
    int ans=0;
    for(u=u;u>0;u-=u&(-u)) ans+=BIT[u];
    return ans;
}
void DFS(int u){
    int v;
    F[P[u]]=getBIT(P[u]);
    updateBIT(P[u],1);
    for(int i=0;i<dinh[u].size();i++){
        v=dinh[u][i];
        if (v!=cha[u]){
            cha[v]=u;
            DFS(v);
        }
    }
    updateBIT(P[u],-1);
}
void solve(){
    cha[0]=-1;
    DFS(0);
    for(int i=1;i<=n;i++) printf("%d\n",F[i]);
}
int main(){
    //freopen("slowdown.inp","r",stdin);
    //freopen("slowdown.out","w",stdout);
    input();
    solve();
    return 0;
}
