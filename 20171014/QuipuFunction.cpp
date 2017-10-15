#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+20;
long long cnt[MAX];
long long a,b,d;
void solve(){
    memset(cnt, 0,sizeof cnt);
    cin >> d;
    long long mx = 0;
    for(long long i = 1; i*i <= b; i++){
        long long mul = (a - 1)/i + 1;
        for(long long j = i*mul; j <= b; j += i) if(i*i <= j){
            if(i % d != 0)
                cnt[j - a]++;
            long long tmp = j/i;
            if(tmp % d != 0 && tmp != i)
                cnt[j - a]++;
        }
    }
    long long ans = 0;
    for(long long i = a; i <= b; i++){
       // cout << i <<" "<< cnt[i - a] << endl;
        ans += cnt[i - a];
    }
    cout << ans <<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> a >> b;
    while(n --)
        solve();
    return 0;
}
