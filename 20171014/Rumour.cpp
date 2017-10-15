#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long x,y;
    cin >> x >> y;
    int cnt = 0;
    while(x != y){
        cnt ++;
        if(x > y)
            x >>= 1;
        else
            y >>= 1;
    }
    cout << cnt << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}
