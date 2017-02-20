#include <bits/stdc++.h>
using namespace std;
const int Max=20;
int D[Max];
int n,m;
int f[1<<Max],all;
int F(int state,int t){
    if(state==all)return 0;
    if(f[state]>=0) return f[state];
    f[state]=1<<30;
    int _st=all&(~state);
    for(int i=0;i<n;i++)
    if(!((1<<i)&state)){
        f[state]=min(f[state],F(state|(1<<i),t-__builtin_popcount(D[i]&state)+__builtin_popcount(D[i]&_st))+t);
    }
    return f[state];
}
main(){
    ios_base::sync_with_stdio(false);
    memset(f,-1,sizeof f);
    int x,y;
    cin>>n>>m;
    all=(1<<n)-1;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        --x;--y;
        D[x]|=1<<y;
        D[y]|=1<<x;
    }
    cout<<F(0,0);
}
