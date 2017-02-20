#include <bits/stdc++.h>
using namespace std;
long long F[5555];
int a[55],x[555],c[555];
void run(){
    memset(F,0,sizeof F);
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    F[0] = 1;
    for(int i=0;i<n;i++)
        for(int j=5000;j>=a[i];j--){
            if(F[j-a[i]]) F[j]|=(F[j-a[i]]<<1);
        }
    cin >> k;
    for(int i=0;i<k;i++)
        cin >> x[i];
    for(int i=0;i<k;i++)
        cin >> c[i];
    for(int i=0;i<k;i++){
        if(F[c[i]]&(1ll<<x[i])) puts("Yes");
        else puts("No");
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int T;
    for(cin>>T;T>0;T--) run();
    }
