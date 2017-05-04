#include <bits/stdc++.h>
using namespace std;
long long F[66];
int find(long long n){
    int t = lower_bound(F,F+61,n) - F - 1;
    if(n == F[t] +1) return 0;
    long long rm = n - F[t] -1;
    return !find(F[t] - rm+1);
}
void solve(int nTest) {
    long long n;
    cin >> n;
    cout << "Case #"<<nTest<<": "<<find(n) <<endl;
}
main() {
    for(int i=1;i<=60;i++){
        F[i] = 2*F[i-1] +1;
    }
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}


