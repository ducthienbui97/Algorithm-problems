#include <set>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#define elif else if
using namespace std;
int a[111][111];
char s[111];
int l[111],r[111];
stack <int> S;
main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++){
        if(s[j-1]=='.') a[i][j]=a[i-1][j]+1;
        else a[i][j]=0;
        //cout<<a[i][j]<<endl;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        int j=1;
        while(j<=n){
            if(S.empty()) S.push(j++);
            elif(a[i][S.top()]>a[i][j]){
                r[S.top()]=j-1;
                S.pop();
            }
            else S.push(j++);
        }
        while(!S.empty()) r[S.top()]=n,S.pop();
        j=n;
        while(j>0){
            if(S.empty()) S.push(j--);
            elif(a[i][S.top()]>a[i][j]){
                l[S.top()]=j;
                S.pop();
            }
            else S.push(j--);
        }
        while(!S.empty()) l[S.top()]=0,S.pop();
        for(j=1;j<=m;j++)
         if(a[i][j]) ans=max(ans,r[j]-l[j]+a[i][j]);
    }
    if(ans) cout<<(ans<<1)-1;
    else cout<<ans;
}
