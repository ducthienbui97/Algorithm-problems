#include <bits/stdc++.h>
using namespace std;
int F[111][1555<<3];
int a[1555];
int s[1555];
int b[1555];
main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
        }
    for(int i = 1; i < n; i++){
        s[i] = 2*s[i-1]+a[i-1];
    }
    for(int i = n-2; i>=0;i--){
        b[i] = 2*b[i+1]+a[i+1];
    }
    for(int i = 0; i < n;i++)
        F[0][i];
    }
