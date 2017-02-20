#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define elif else if
#define mp make_pair

using namespace std;
const int base=1e5+69;
int F[base];
int p[base<<3];
int pow[base];
int H[base<<3];
int all[base<<3];
int a[base];
int n;
void init(int node,int l,int r){
    if(l==r){
        H[node]=a[l];
        p[node]=base;
       return;
    }
    init(node<<1,l,(l+r)>>1);
    init((node<<1)+1,((l+r)>>1)+1,r);
    H[node]=H[node<<1]*p[(node<<1)+1]+H[(node<<1)+1];
    p[node]=pow[r-l+1];
}
void setall(int node,int l,int r){
    if(l!=r){
        all[node<<1]=all[(node<<1)+1]=all[node];
    }
    H[node]=F[r-l+1]*all[node];
    all[node]=0;
}
pair<int,int> get(int node,int l,int r,int u,int v){
    if(all[node]) setall(node,l,r);
    if(u>r||l>v) return mp(0,1);
    if(u<=l&&r<=v){
        return mp(H[node],p[node]);
    }
    pair<int,int> k1=get(node<<1,l,(l+r)>>1,u,v);
    pair<int,int> k2=get((node<<1)+1,((l+r)>>1)+1,r,u,v);
    return mp(k1.first*k2.second+k2.first,k1.second*k2.second);
}
void update(int node,int l,int r,int u,int v,int val){
    if(all[node]) setall(node,l,r);
    if(u>r||l>v) return ;
    if(u<=l&&r<=v){
        all[node]=val;
        setall(node,l,r);
        return;
    }
    update(node<<1,l,(l+r)>>1,u,v,val);
    update((node<<1)+1,((l+r)>>1)+1,r,u,v,val);
    H[node]=H[node<<1]*p[(node<<1)+1]+H[(node<<1)+1];
}
main(){
    //DECORATOR
    //freopen("DECORATOR.INP","r",stdin);
    //freopen("DECORATOR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    pow[0]=1;
    for(int i=1;i<=n;i++){
        pow[i]=pow[i-1]*base;
    }
    F[0]=0;
    for(int i=1;i<=n;i++)
        F[i]=F[i-1]*base+1;
    init(1,1,n);
    int q;
    for(cin>>q;q--;){
        int x,y,z,t;
        cin>>x>>y>>z>>t;
        if(!x){
            update(1,1,n,y,z,t);
        }else{
            putchar(get(1,1,n,y,y+t-1)==get(1,1,n,z,z+t-1)?'+':'-');
        }
    }
}
