#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cout <<"YES"<<endl;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y,tmp;
        cin >> x >> y;
        cout << (((x&1)<<1)|(y&1))+1 <<endl;
        cin >> x >> y;
    }
}
