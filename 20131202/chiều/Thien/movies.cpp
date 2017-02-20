#include <iostream>
#include <cstdio>
#include <cstring>
#define mp make_pair
#include <string>
#include <vector>
#include <algorithm>
#define elif else if
using namespace std;
const int Maxn=2e5+20;
int A[Maxn];
int L[Maxn];
int n,m;
void update(int x,int val){
    for(;x<Maxn;x+=(x&(-x))) A[x]+=val;
}
int get(int x){
    int S;
    for(;x>0;x-=(x&(-x))) S+=A[x];
    return S;
}
main(){
    freopen("movies.inp","r",stdin);
    freopen("movies.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int cnt=n;
    for(int i=1;i<=n;i++){
        L[i]=n-i+1;
        update(L[i],1);
    }
    int x;
    for(int i=1;i<=m;i++){
        cin>>x;
        printf("%d ",n-get(L[x])+1);
        update(L[x],-1);
        L[x]=++cnt;
        update(L[x],1);
    }
}
