#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <climits>
#include <algorithm>
#define elif else if
using namespace std;
vector <int> d[222];
vector<int> dx[222];
int n;
int cnt;
int vs[222];
void dfs(int node,int tt){
    vs[node]=tt;
    dx[tt].push_back(node);
    for(int i=0;i<(int) d[node].size();i++)
        if(vs[d[node][i]]!=tt) dfs(d[node][i],tt);
}
void doit(){
    int m=INT_MAX;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        dfs(i,i);
        if((int)dx[i].size()<m){
            m=dx[i].size();
            ans=dx[i];
        }
    }
    cout<<m<<endl;
    for(int i=0;i<m;i++)
        cout<<ans[i]<<' ';
}
main(){
    freopen("FLOWERS.INP","r",stdin);
    freopen("FLOWERS.OUT","w",stdout);
    int x,y;
    scanf("%d",&n);
    while(scanf("%d%d",&x,&y)!=EOF){
        d[x].push_back(y);
    }
    doit();
}
