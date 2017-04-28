#include <bits/stdc++.h>
using namespace std;

void solve(int nTest){
    long long n,m;
    cin >> n >> m;
    n = min(n,m);
    cout <<"Case #"<<nTest<<": "<<n*(n-1)/2+n<<endl;
}
main(){
   freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)solve(i);
}

