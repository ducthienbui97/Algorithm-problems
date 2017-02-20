#include <bits/stdc++.h>
using namespace std;
int a[1111][1111];
int b[1111][1111];
int l[1111][1111];
int r[1111][1111];
vector<int> val;
stack<int> ms;
int n,m;
int ok(int k){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        b[i][j]=(a[i][j]>=k)?b[i-1][j]+1:0;
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
        while(!ms.empty()&&b[i][ms.top()]>b[i][j]){
            r[i][ms.top()]=j;
            ms.pop();
        }
        ms.push(j);
       }
       while(!ms.empty()) r[i][ms.top()]=m+1,ms.pop();
       for(int j=m;j>0;j--){
        while(!ms.empty()&&b[i][ms.top()]>b[i][j]){
            l[i][ms.top()]=j;
            ms.pop();
        }
        ms.push(j);
       }
       while(!ms.empty()) l[i][ms.top()]=0,ms.pop();;
    }
    int rep=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
        rep=max(rep,(r[i][j]-l[i][j]-1)*b[i][j]);
        }
    return rep;
}
main() {
    freopen("burrow.in","r",stdin);
    freopen("burrow.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>a[i][j];
        val.push_back(a[i][j]);
    }
    sort(val.begin(),val.end());
    val.resize(unique(val.begin(),val.end())-val.begin());
    int l=0,r=val.size()-1;
    int ans1=0,ans2=0;
    while(l<=r){
        int mid=(l+r)>>1;
        int tmp=ok(val[mid]);
        //cerr<<endl;
        if(tmp>=k){
            ans1=val[mid];
            ans2=tmp;
            l=mid+1;
        }else r=mid-1;
    }
    printf("%d %d\n",ans1,ans2);
}

