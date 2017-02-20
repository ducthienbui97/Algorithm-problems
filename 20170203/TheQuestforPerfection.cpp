#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bool p[100000];
void init(){
    p[0] = true;
    p[1] = true;
    for(int i=2;i < 100000;i++)
        if(!p[i]){
            for(int j=i+i;j<100000;j+=i)
                p[j] = true;
            primes.push_back(i);
        }
}
bool solve(){
    long long n,N;
    cin >> n;
    N = n;
    long long product=1;
    if(n==1) return false;
    if(n==0) return true;
    for(int i=0;i<primes.size() && primes[i] <= n; i++)
    if(n%primes[i]==0){
        long long sum = 1;
        while(n%primes[i]==0){
            sum = sum*primes[i] + 1;
            n/=primes[i];
        }
        product*=sum;
        if(product > (N<<1)) return false;
    }
    if(n > 1)
        product*=(n+1);
    return product - N == N;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    init();
    for(cin>>t;t>0;t--) if (solve()) puts("yes"); else puts("no");
    return 0;
}
