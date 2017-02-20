#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <utility>
#define elif else if
using namespace std;
vector<pair<int,int> > d;
const int Maxn=200011;
int S[Maxn<<3];
vector<int> dis;
int lazy[Maxn<<3];
void update(int node,int l,int r,int u,int v,int val){
    if(l>r||r<u||l>v) return;
    if(u<=l&&r<=v) {
        S[node]+=val;
        lazy[node]+=val;
        return;
    }
    update(node<<1,l,(l+r)>>1,u,v,val);
    update((node<<1)+1,((l+r)>>1)+1,r,u,v,val);
    S[node]=max(S[node<<1],S[(node<<1)+1])+lazy[node];
}
void openfile(){
    freopen("Gold.inp","r",stdin);
    freopen("Gold.out","w",stdout);
}
vector<int> zip;
main(){
    #ifndef HYQ
    openfile();
    #endif // HYQ
    ios_base::sync_with_stdio(false);
    int s,w,n;
    int x,y;
    cin>>x>>y;
    cin>>s>>w;
    cin>>n;
    d.resize(n);
    dis.resize(n);
    for(int i=0;i<n;i++)
        cin>>d[i].first>>d[i].second,zip.push_back(d[i].second),zip.push_back(d[i].second-w);
    sort(d.begin(),d.end());
    sort(zip.begin(),zip.end());
    for(int i=0;i<n;i++){
        dis[i]=lower_bound(zip.begin(),zip.end(),d[i].second-w)-zip.begin()+1;
        d[i].second=lower_bound(zip.begin(),zip.end(),d[i].second)-zip.begin()+1;
    }
    int j=0;
    int l=0;
    int ans=1;
    for(int i=0;i<d.size();i++){
        while(i+1<d.size()&&d[i].first==d[i+1].first)  update(1,1,Maxn,dis[i],d[i].second,1),i++;
        update(1,1,Maxn,dis[i],d[i].second,1);
        while(j<i&&d[j].first+s<d[i].first){
           update(1,1,Maxn,dis[j],d[j].second,-1);
            j++;
        }
        ans=max(ans,S[1]);
    }
    cout<<ans;
}
/*
4 4 1 1
9
0 0
1 0
1 1
0 1
2 2
3 3
3 2
2 3
3 3
*/
