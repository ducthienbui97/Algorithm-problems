#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10011;
const long long INF = 1ll<<35;
long long IT[Maxn << 3];
void init(int node,int l,int r){
    IT[node] = INF;
    if(l==r) return;
    init(node<<1,l,(l+r)>>1);
    init((node<<1)+1,((l+r)>>1)+1,r);
}
void Set(int node,int l,int r,int u,long long v){
    if(l==r){
        IT[node] = min(IT[node],v);
    }
    else{
        int mid = (l+r)>>1;
        if(u>mid)
            Set((node<<1)+1,mid+1,r,u,v);
        else
            Set((node<<1),l,mid,u,v);
        IT[node] = min(IT[node<<1],IT[(node<<1)+1]);
    }
}
long long Get(int node,int l,int r,int u,int v){
    if(u > v || u > r || v < l) return INF;
    if(u<=l&&r<=v) return IT[node];
    return min(Get(node<<1,l,(l+r)>>1,u,v),Get((node<<1)+1,((l+r)>>1)+1,r,u,v));
}
void solve(int nTest){
    int n,l;
    long long m;
    cin >> n >> m >> l;
    l++;
    init(1,1,l);
    Set(1,1,l,1,0);
    for(int i=0;i<n;i++){
        int a,b,x;
        cin >> a >> b >> x;
        for(int c=l;c>1;c--){
            long long tmp = Get(1,1,l,c-b,c-a);
            Set(1,1,l,c,tmp + x);
        }
    }
    long long ans = Get(1,1,l,l,l);
    cerr <<nTest<<endl;
    cout << "Case #"<<nTest<<": "<<(ans <= m ? to_string(ans) : "IMPOSSIBLE")<<endl;
}
main(){
    freopen("D-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
