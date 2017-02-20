// TCO 2012 2C 500
#include <bits/stdc++.h>
#define elif else if
#define X first
#define Y second
using namespace std;
int n;
const int Max=333000;
typedef pair<int,int> point;
vector<point> a;
int xx[4],yy[4];
vector<int> x,y;
int F[Max];
int M[Max];
long long N[Max<<3];
int lz[Max<<3],num[Max<<3];
void update(int x){
    for(;x<=n;x+=(x&(-x))) F[x]++;
}
int get(int x){
    int rep=0;
    for(;x>0;x-=(x&(-x))) rep+=F[x];
    return rep;
}
void init(int now,int l,int r){
    lz[now]=0;
    num[now]=(r-l+1);
    if(l==r){
        N[now]=M[l];
        return;
    }
    else {
        init(now<<1,l,(l+r)>>1);
        init((now<<1)+1,((l+r)>>1)+1,r);
        N[now]=N[now<<1]+N[(now<<1)+1];
    }
}
void update(int now,int l,int r,int u,int v){
    if(l>v||r<u||u>v) return;
    if(u<=l&&r<=v){
        lz[now]++;
        N[now]-=num[now];
        return;
    }
    update(now<<1,l,(l+r)>>1,u,v);
    update((now<<1)+1,((l+r)>>1)+1,r,u,v);
    N[now]=N[now<<1]+N[(now<<1)+1]-1ll*lz[now]*num[now];
}
void clear(int now,int l,int r,int v){
    if(l>v||r<v) return;
    if(l==r){
        N[now]=0,lz[now]=0;
        num[now]=0;
        return;
    }
    if(l!=r){
        clear(now<<1,l,(l+r)>>1,v);
        clear((now<<1)+1,((l+r)>>1)+1,r,v);
        num[now]=num[(now<<1)]+num[((now<<1)+1)];
        N[now]=N[now<<1]+N[(now<<1)+1]-1ll*lz[now]*num[now];
    }
}
pair<long long,int> get(int now,int l,int r,int u,int v){
    if(l>v||r<u||u>v) return make_pair(0,0);
    if(u<=l&&r<=v) return make_pair(N[now],num[now]);
    pair<long long,int> k1=get(now<<1,l,(l+r)>>1,u,v);
    pair<long long,int> k2=get((now<<1)+1,((l+r)>>1)+1,r,u,v);
    return make_pair(k1.first+k2.first-1ll*(k1.second+k2.second)*lz[now],k1.second+k2.second);
}
main() {
  //  freopen("count.inp","r",stdin);
  //  freopen("count.out","w",stdout);
    ios_base::sync_with_stdio(false);
   cin>>n;
   for(int i=0;i<4;i++)
    cin>>xx[i];
   for(int i=0;i<4;i++)
    cin>>yy[i];
   x.resize(n);
   y.resize(n);
   a.resize(n);
   x[0]=xx[0];
   y[0]=yy[0];
   a[0]=(point(x[0],y[0]));
   for(int i=1;i<n;i++){
    x[i]=(1ll*x[i-1]*xx[1]+xx[2])%xx[3];
    y[i]=(1ll*y[i-1]*yy[1]+yy[2])%yy[3];
    a[i]=(point(x[i],y[i]));
   }
   sort(y.begin(),y.end());
   for(int i=0;i<n;i++){
    a[i].Y=upper_bound(y.begin(),y.end(),a[i].Y)-y.begin();
   }
   sort(a.begin(),a.end());
   for(int i=0;i<n;i++){
    M[a[i].Y]=i-get(a[i].Y);
    update(a[i].Y);
   }

   init(1,1,n);
   long long ans=0;
   for(int i=0;i<n;i++){
    ans+=get(1,1,n,a[i].Y+1,n).first;
    update(1,1,n,1,a[i].Y-1);
    clear(1,1,n,a[i].Y);
   }
   printf("%lld",ans);
}
