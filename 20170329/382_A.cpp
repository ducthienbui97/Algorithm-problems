#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long f1 = 1,f2 = 1;
    int t = 0;
    while(f2 <= n){
        t++;
        long long tmp = f1+f2;
        f1=f2;
        f2=tmp;
    }
    cout << t-1 <<endl;
}
