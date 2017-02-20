#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int Maxn=3e5+20;
int Node[Maxn<<2],n,m;
void update(int node,int l,int r,int u,int v,int val) {
    if(l>r||l>v||u>r) return;
    if(l<=u&&val<=Node[node]+u-l) return;
    if(l>u&&val+l-u<=Node[node]) return;
    if(u<=l&&r<=v) {
        Node[node]=val+l-u;
        return;
        }
    int mid=(l+r)>>1;
    update(node<<1,l,mid,u,v,val);
    update((node<<1)+1,mid+1,r,u,v,val);
    }
int find(int node,int l,int r,int u) {
    if(l>u||r<u) return 0;
    if(l==r) return Node[node];
    return max(max(find(node<<1,l,(l+r)>>1,u),find((node<<1)+1,((l+r)>>1)+1,r,u)),Node[node]+u-l);
    }
main() {
    memset(Node,-0x3f,sizeof Node);
    freopen("trading.in","r",stdin);
    freopen("trading.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int x,y,z;
    for(int i=1; i<=m; i++) {
        cin>>x>>y>>z;
        update(1,1,n,x,y,z);
        }
    for(int i=1; i<=n; i++) {
        printf("%d ",find(1,1,n,i));
        }
    }
