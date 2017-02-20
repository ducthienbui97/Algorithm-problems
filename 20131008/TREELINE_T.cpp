#include <bits/stdc++.h>
#define elif else if
using namespace std;

queue<int>  q;
const int Maxn=1e5+10;
int a[Maxn];
int vs[Maxn];
int next[Maxn];
main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i],next[i]=i+1;
    a[n+1]=1<<30;
    for(int i=n; i>0; i--)
        if(a[i]<=a[i-1]) q.push(i-1),vs[i]=1;
    int cnt=0;
    int ans=0;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        int r=next[x];
        if(a[next[r]]<=a[x] && !vs[x]) q.push(x),vs[next[r]]=vs[r]+1;
        next[x]=next[r];
        ans=max(ans,vs[r]);
        }
    cout<<ans<<endl;
    }
