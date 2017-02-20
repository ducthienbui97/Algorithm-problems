#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n;
    stack<int> s;
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        while(!s.empty() && s.top() < x){
            s.pop();
            ans++;
        }
        if(!s.empty()) ans ++;
        s.push(x);
    }
    cout << ans <<endl;
}
