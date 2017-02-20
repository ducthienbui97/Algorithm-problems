#include <bits/stdc++.h>
#define elif else if
using namespace std;
#define int long long
const int Maxn=1e5+10;
int root[Maxn];
const int mod=1e9+7;
int n,m;
int findroot(const int& x) {
    if(root[x]!=x) return root[x]=findroot(root[x]);
    return x;
    }
struct edge {
    int u,v,w;
    bool operator < (const edge& X) const {
        return w<X.w;
        }
    };
vector<edge> lis;
main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int x,y,z;
    lis.resize(m);
    for(int i=1; i<=n; i++)
        root[i]=i;
    for(int i=0; i<m; i++) {
        cin>>lis[i].u>>lis[i].v>>lis[i].w;
        }
    int ans=0;
    int ans2=1;
    sort(lis.begin(),lis.end());
    for(int i=0; i<m; i++) {
        int j=i;
        set<pair<int,int> > ms;
        while(j+1<m&&lis[i].w==lis[j+1].w) j++;
        int num=0;
        for(int l=i; l<=j; l++) {
            x=findroot(lis[l].u);
            y=findroot(lis[l].v);
            if(x!=y) {
                num++;
                if(x>y) swap(x,y);
                ms.insert(make_pair(x,y));
                }
            }
        int cal=0;
        for(__typeof(ms.begin()) it=ms.begin(); it!=ms.end(); it++)
          if(findroot(it->first)!=findroot(it->second))  root[findroot(it->first)]=findroot(it->second),cal++;
        ans+=cal*lis[i].w;
        if(num==3){
            if(cal==1||(cal==2&&ms.size()==3)) ans2*=3;
            if(cal==2&&ms.size()==2) ans2*=2;
        }
        if(cal==1&&num==2) ans2*=2;
        ans2%=mod;
        i=j;
        }
    cout<<ans<<" "<<ans2<<endl;
    }

