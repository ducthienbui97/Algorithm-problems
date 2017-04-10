#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6+20;
bool isNotPrime[Maxn];
bool done[Maxn];
vector<int> primes;
int cnt[Maxn];
main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i=2; i<Maxn; i++)
        if(!isNotPrime[i]) {
            primes.push_back(i);
            for(int j=i+i; j<Maxn; j+=i)
                isNotPrime[j] = true;
        }
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if(done[x]) continue;
        done[x] = true;
        for(int p:primes) {
            if(p>x) break;
            if(!isNotPrime[x]){
                cnt[x] = max(cnt[x],1);
                break;
            }
            int cn = 0;
            while(x%p==0) cn++,x/=p;
            cnt[p] = max(cnt[p],cn);
        }
    }
    for(int p:primes){
        int cn = 0;
        while(k%p==0) cn++,k/=p;
        if(cn > cnt[p]){
            cout <<"No";
            return 0;
        }
    }
    cout <<"Yes";
}
