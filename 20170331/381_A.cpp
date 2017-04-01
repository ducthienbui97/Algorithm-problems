#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int t = 1<<30;
    while(m--){
        int x,y;
        cin >> x >>y;
        t = min(t,(y-x)+1);
    }
    cout << t <<endl;
    for(int i=0;i<n;i++)
        cout << i%t <<" ";
}
