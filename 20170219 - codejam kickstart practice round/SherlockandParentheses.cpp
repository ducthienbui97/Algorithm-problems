#include <bits/stdc++.h>
using namespace std;
main(){
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int l,r;
        cin >> l >> r;
        cout <<"Case #"<<i<<": "<< 1ll*min(l,r)*(min(l,r) + 1)/2 <<endl;;
    }

}
