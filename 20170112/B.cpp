#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+20;
int cnt[maxn];
bool vs[maxn];
main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x;
    int ans = 1;
    for(int i=0; i<n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for(int i=2; i < maxn; i++)
        if(!vs[i]) {
            int con = 0 ;
            for(int j=i; j < maxn; j += i){
                con += cnt[j];
                vs[j] = true;
            }
            ans = max(ans,con);
            }
    cout << ans <<endl;
}
