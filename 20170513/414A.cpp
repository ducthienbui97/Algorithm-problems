#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    int ans =0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x>b&&x<c) ans ++;
    }
    cout << ans;
}
