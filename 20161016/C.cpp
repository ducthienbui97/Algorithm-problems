#include <bits/stdc++.h>
using namespace std;
int a[10];
void solve() {
    int cnt = 0;
    int Min = 4;
    for(int i = 0 ; i < 10; i++) {
        cin >> a[i];
        if(a[i]==0) cnt ++;
        else Min = min(Min,a[i]);
        }
    if(cnt == 1) cout << Min <<'\n';
    else {
        for(int i = 0; i < 7; i++) {
            int temp = max(max(a[i],a[i+1]),max(a[i+2],a[i+3]))+1;
            for(int j = 0 ; j < i ; j++)
                temp = min(temp,a[j]);
            for(int j = i + 4; j <10; j++)
                temp = min(temp,a[j]);
            if(temp == max(max(a[i],a[i+1]),max(a[i+2],a[i+3]))+1) {
                cout << 1 << '\n';
                return;
                }
            }
        cout << 0 <<'\n';
        }
    }
main() {
    ios_base::sync_with_stdio(false);
    int t;
    for(cin >> t; t-->0;) solve();
    }
/*
6
0 5 7 5 7 10 9 11 8 8
0 3 3 3 3 3 3 3 3 3
0 0 0 2 3 3 3 3 3 3
0 0 1 2 2 3 3 3 3 3
0 0 0 3 0 3 3 3 3 3
0 0 0 0 0 3 3 3 3 3
*/
