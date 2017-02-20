#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Max=5e5+10;
int pr[Max];
int st[Max],fn[Max];
vector<int> d[Max];
int cnt,n,m;
int ini[Max];
int N[Max<<3];
int dfs(int t){
    st[t]=++cnt;
    for(int i=0;i<d[t].size();i++)
    dfs(d[t][i]);
    fn[t]=cnt;
}
void init(int node,int l,int r){
    if(l==r) N[node]=ini[l];
    else{
        init(node<<1,l,(l+r)>>1);
        init((node<<1)+1,((l+r)>>1)+1,r);
    }
}
void update(int node,int l,int r,int u,int v,int val){
    if(l>r||u>v||l>v||r<u) return;
    if(u<=l&&r<=v){
        N[node]+=val;
        return;
    }
    update(node<<1,l,(l+r)>>1,u,v,val);
    update((node<<1)+1,((l+r)>>1)+1,r,u,v,val);
}
int get(int node,int l,int r,int t){
    if(l==r) return N[node];
    if(t>((l+r)>>1)){
        return get((node<<1)+1,((l+r)>>1)+1,r,t)+ N[node];
    }
    else return get(node<<1,l,(l+r)>>1,t) + N[node];
}
char c[11];
main() {
    ios_base::sync_with_stdio (false);
    cin>>n>>m;
    cin>>pr[1];
    int x,y;
    for(int i=2;i<=n;i++){
        cin>>pr[i]>>x;
        d[x].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        ini[st[i]]=pr[i];
    init(1,1,n);
    while(m--){
        cin>>c;
        if(c[0]=='u'){
                cin>>x;
                printf("%d\n",get(1,1,n,st[x]));
        }else{
            cin>>x>>y;
            update(1,1,n,st[x]+1,fn[x],y);
        }
    }
}
