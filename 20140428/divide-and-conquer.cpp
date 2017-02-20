#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;

const int Maxn=1e5+20;
int Next[Maxn];
int n,x[Maxn],g[Maxn],d[Maxn];
long long Node[Maxn<<3];
long long sum[Maxn];
void update(int node,int l,int r,int u,long long val){
    if(l>r||l>u||u>r) return;
    if(l==r){
        Node[node]=val;
        return;
    }
    update(node<<1,l,(l+r)>>1,u,val);
    update((node<<1)+1,((l+r)>>1)+1,r,u,val);
    Node[node]=min(Node[node<<1],Node[(node<<1)+1]);
}
int find(int node,int l,int r,long long H){
    if(Node[node]>H) return -1;
    if(l==r)   return r;
    if(Node[node<<1]<=H) return find(node<<1,l,(l+r)>>1,H);
    else return find((node<<1)+1,((l+r)>>1)+1,r,H);
}
main(){
    freopen("divide.in","r",stdin);
    freopen("divide.out","w",stdout);
    memset(Node,0x3f,sizeof Node);
    ios_base::sync_with_stdio(false);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>g[i]>>d[i];
        ans=max(ans,1ll*g[i]);
    }
    Next[n]=0;
    for(int i=1;i<=n;i++)
        Next[i]=x[i+1]-x[i];
    long long D,E;
    D=E=0;
    for(int i=1;i<=n;i++){
        E+=d[i];
        sum[i]=sum[i-1]+g[i];
        if(E>=D) ans=max(ans,sum[i]);
        ans=max(ans,1ll*g[i]);
        int tmp=find(1,1,n,E-D);
        if(tmp>0) ans=max(ans,sum[i]-sum[tmp]);
        D+=Next[i];
        update(1,1,n,i,E-D);
    }
    printf("%lld",ans);
}
