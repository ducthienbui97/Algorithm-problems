#include <bits/stdc++.h>
using namespace std;
const int Max=1e5+20;
vector<int> prime;
int di[Max];
vector<int> a;
struct IT{
  vector<int> node;
  vector<int> id;
  int GET(int l,int r){
    if(!id.size()) return -(1<<30);
    return get(0,0,id.size()-1,lower_bound(id.begin(),id.end(),l)-id.begin(),upper_bound(id.begin(),id.end(),r)-id.begin()-1);
  }
  int get(int now,int l,int r,int u,int v);
  void init(){
      node.resize(id.size()<<3);
      init(0,0,id.size()-1);
  }
  void init(int now,int l,int r);
};
int IT::get(int now,int l,int r,int u,int v){
    if(l>v||r<u||l>r) return -(1<<30);
    if(u<=l&&r<=v) return node[now];
    return max(get((now<<1)+1,l,(l+r)>>1,u,v),get(((now<<1)+2),((l+r)>>1)+1,r,u,v));
   }
void IT::init(int now,int l,int r){
    if(l>r) return ;
    if(l==r) node[now]=a[id[l]];
    else{
        init((now<<1)+1,l,(l+r)>>1);
        init((now<<1)+2,((l+r)>>1)+1,r);
        node[now]=max(node[(now<<1)+1],node[(now<<1)+2]);
    }
}
void era(){
    di[1]=1;
    for(int i=2;i<Max;i++)
    if(!di[i]){
        prime.push_back(i);
        di[i]=i;
        if(1ll*i*i<Max)
        for(int j=i*i;j<Max;j+=i)
            di[j]=i;
    }
}
IT tree[Max];
vector<int> locat[Max];
int n,m;
main(){
    ios_base::sync_with_stdio(false);
    era();
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        locat[a[i]].push_back(i);
        int tmp=a[i];
        while(tmp>1){
            int t=di[tmp];
            tree[t].id.push_back(i);
            while(!(tmp%t)) tmp/=t;
        }
    }
    for(int i=0;i<prime.size();i++)
        tree[prime[i]].init();
    int g,x,y;
    for(;m--;){
        cin>>g>>x>>y;
        --x,--y;
        int rep=-1;
        while(g>1){
            int t=di[g];
            rep=max(rep,tree[t].GET(x,y));
            while(!(g%t)) g/=t;
        }
        if(rep==-1) puts("-1 -1");
        else{
            printf("%d %d\n",rep,upper_bound(locat[rep].begin(),locat[rep].end(),y)-lower_bound(locat[rep].begin(),locat[rep].end(),x));
        }
    }
}

