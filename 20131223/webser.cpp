#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
vector<pair<int,int> > lis;
vector<pair<pair<int,int> ,int > >query;
vector<int> ans;
const int Maxn=1e6+20;
int S[Maxn];
void update(int i){
    for(;i<Maxn;i+=(i&(-i))) S[i]++;
}
int get(int i){
    int rep=0;
    for(;i>0;i-=(i&(-i))) rep+=S[i];
    return rep;
}
int n,m;
main() {
    freopen("webser.inp","r",stdin);
    freopen("webser.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    query.resize(m);
    ans.resize(m);
    lis.resize(n);
    for(int i=0;i<n;i++)cin>>lis[i].first>>lis[i].second;
    for(int i=0;i<m;i++)cin>>query[i].first.first>>query[i].first.second,query[i].second=i;
    sort(lis.begin(),lis.end());sort(query.begin(),query.end());
    reverse(lis.begin(),lis.end());
    reverse(query.begin(),query.end());
    for(int i=0,j=0;i<m;i++){
        while(j<n&&lis[j].first>=query[i].first.first) update(lis[j++].second);
        ans[query[i].second]=get(query[i].first.second);
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    }
