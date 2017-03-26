#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5+20;
int IT[Maxn<<3],lz[Maxn<<3];
int value[Maxn];
void lazy(int node,int l,int r){
    IT[node] += lz[node];
    if(l!=r){
        lz[(node<<1)] += lz[node];
        lz[(node<<1)+1]+=lz[node];
    }
    lz[node] = 0;
}
void update(int node,int l,int r,int u,int v,int a){
    lazy(node,l,r);
    if(u>r||v<l) return;
    if(u<=l&&r<=v){
        lz[node] += a;
        return;
    }
    update(node<<1,l,(l+r)>>1,u,v,a);
    update((node<<1)+1,((l+r)>>1)+1,r,u,v,a);
    IT[node] = max(IT[node<<1]+lz[node<<1],IT[(node<<1)+1]+lz[(node<<1)+1]);
}
int get(int node,int l,int r){
    lazy(node,l,r);
    if(l==r) return IT[node] > 0? l : 0;
    if(IT[(node<<1)+1]+lz[(node<<1)+1] > 0) return get((node<<1)+1,((l+r)>>1)+1,r);
    return get(node<<1,l,(l+r)>>1);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    value[0] = -1;
    for(int i=0;i<n;i++){
        int p,t;
        cin >> p >> t;
        if(t){
            cin >> value[p];
            update(1,1,n,1,p,1);
        }else{
            update(1,1,n,1,p,-1);
        }
        p = get(1,1,n);
        cout << value[p]<<endl;
    }
}
