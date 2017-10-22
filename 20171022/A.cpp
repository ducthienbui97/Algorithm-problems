#include <bits/stdc++.h>
using namespace std;
long long a,p;
int n;
long long power(long long x, int t){
    if(!t) return 1;
    if(t & 1)
        return power(x,t - 1)*x%p;
    long long tmp = power(x,t/2);
    return tmp*tmp%p;
}
void solve(int n_test){
    cin >> a >> n >> p;
    for(int i = 1; i <= n; i++){
        a = power(a,i)%p;
    }
    cout << "Case #" << n_test << ": " << a << "\n";
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}
