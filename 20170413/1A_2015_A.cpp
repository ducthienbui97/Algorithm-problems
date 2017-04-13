#include <bits/stdc++.h>
using namespace std;
int m[1111];
void solve(int nTest){
    int Max = 0;
    int n;
    int ans1=0,ans2=0;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> m[i];
    for(int i=1;i<n;i++){
        Max = max(m[i-1]-m[i],Max);
        ans1 += max(m[i-1]-m[i],0);
    }
    for(int i=0;i<n-1;i++)
        ans2 += min(Max,m[i]);
    cout <<"Case #"<<nTest<<": "<<ans1<<" "<<ans2<<endl;;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
