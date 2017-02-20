#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    int k,a,b;
    cin >> k >> a >> b;
    int num = a/k + b/k;
    if((a/k == 0 && b%k > 0)||
       (a%k > 0 && b/k == 0)) num = -1;
    cout << num;
}


