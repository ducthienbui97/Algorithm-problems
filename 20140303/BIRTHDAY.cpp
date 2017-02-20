#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Max=1e7+20;
const int Mod=1e9+7;
int G[Max];
int ans[Max];
int INF=1e9;
main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int p;
    memset(ans,0x3f,sizeof ans);
    ans[0]=0;
    for(int i=1;i<=n;i++){
        cin>>p;
        G[0]=max(G[0],p);
        for(int j=p;j<Max;j+=p)
            G[j]=max(G[j],p);
    }
    queue<int> q;
    q.push(0);
    for(int i=1;i<Max;i++){
        while(!q.empty()&&q.front()+G[q.front()]-1<i) q.pop();
        if(q.empty()) break;
        ans[i]=ans[q.front()]+1;
        q.push(i);
    }
    while(m--){
        cin>>n;
        if(ans[n]>=INF) printf("oo\n");
        else printf("%d\n",ans[n]);
    }
}
