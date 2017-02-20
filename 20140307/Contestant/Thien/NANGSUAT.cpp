#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Max=1111;
vector<int> lis;
int a[Max][Max];
int X[Max],Y[Max];
int n;
bool vs[Max];
bool dfs(int u,int k){
    if(!u) return true;
    if(vs[u]) return false;
    vs[u]=true;
    for(int i=1;i<=n;i++)
    if(a[u][i]>=k&&dfs(Y[i],k)){
        X[u]=i;
        Y[i]=u;
        return true;
    }
    return false;
}
bool ok(int k){
    memset(X,0,sizeof X);
    memset(Y,0,sizeof Y);
    int c=0,cc=0;
    do{
        c=cc;
        memset(vs,0,sizeof vs);
        for(int i=1;i<=n;i++)
        if(!X[i]&&dfs(i,k)) cc++;
    }while(c<cc);
     return cc==n;
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        cin>>a[i][j];
        lis.push_back(a[i][j]);
    }
    sort(lis.begin(),lis.end());
    lis.resize(unique(lis.begin(),lis.end())-lis.begin());
    int l=0;
    int r=lis.size()-1;
    int ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(ok(lis[mid])) ans=max(ans,lis[mid]),l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
}

/*
4
9 4 4 12
8 7 8 13
2 2 8 3
6 7 3 7
*/
