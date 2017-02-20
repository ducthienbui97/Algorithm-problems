#include<bits/stdc++.h>
using namespace std;
int main() {
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++) {
        int n;
        int m;
        int x;
        cin >> n >> m >> x;
        vector<int> a(n);
        vector<int> b(m);
        int s = 0;
        map<int,int> ms;
        ms[0] = 0;
        for(int a_i = 0; a_i < n; a_i++) {
            cin >> a[a_i];
            if(s<=x)
                s += a[a_i];
            if(s<=x)
                ms[-s] = a_i+1;

        }
        s = 0;
        int ans = 0;
        for(int b_i = 0; b_i < m; b_i++) {
            cin >> b[b_i];
            if(s <= x)
                s += b[b_i];
            if(s<=x)
                ans = max(ans,b_i + 1 + (ms.lower_bound(s - x)->second));
        }
        // your code goes here
        cout << ans <<endl;

    }
    return 0;
}
