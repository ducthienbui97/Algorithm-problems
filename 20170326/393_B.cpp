#include <bits/stdc++.h>
using namespace std;
int a[100011];
int F[100011];
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        F[i] = F[i-1] + 20;
        F[i] = min(F[i],F[upper_bound(a+1,a+i,a[i]-90)-a-1]+50);
        F[i] = min(F[i],F[upper_bound(a+1,a+i,a[i]-1440)-a-1]+120);
        cout << F[i] - F[i-1] <<endl;
    }
}
