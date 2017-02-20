#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Maxn=170011;
vector<int> D[Maxn];
int P[Maxn][17];
int Min[Maxn];
int T[Maxn],H[Maxn],N[Maxn];
bool cmp(int x,int y){
    return Min[x]<Min[y];
}
int cnt;
void dfs(int t){
    Min[t]=t;
    for(int i=0;i<D[t].size();i++) P[D[t][i]][0]=t,dfs(D[t][i]);
    sort(D[t].begin(),D[t].end(),cmp);
    if(D[t].size()) Min[t]=min(Min[t],Min[D[t][0]]);
}
void dfs2(int t){
    for(int i=0;i<D[t].size();i++) dfs2(D[t][i]);
    T[t]=++cnt;
    H[cnt]=t;
}
set<int> S;
main(){
//    freopen("out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int x,root;
    int l,r;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x) D[x].push_back(i);
        else root=i;
    }
    dfs(root);
    dfs2(root);
    for(int i=1;i<17;i++)
        for(int j=1;j<=n;j++)
        P[j][i]=P[P[j][i-1]][i-1];
    for(int i=1;i<=n;i++) S.insert(i);
    for(int i=0;i<q;i++){
        int t;
        cin>>t>>x;
        if(t==1) {
            int last=0;
            while(x--) last=H[*S.begin()],N[last]=true,S.erase(T[last]);
            printf("%d\n",last);
        }
        else{
            if(!N[x]){
                puts("0");
                continue;
            }
            int tmp=0;
            for(int i=16;i>=0;i--)
                if(N[P[x][i]]) tmp+=(1<<i),x=P[x][i];
            S.insert(T[x]);
            N[x]=false;
            printf("%d\n",tmp);
        }
    }
}
