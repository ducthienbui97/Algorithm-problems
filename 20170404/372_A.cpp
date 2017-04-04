#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    long long cur = 2;
    int n;
    cin >> n;
    for(int i=2;i <= n+1; i++){
        long long tmp = 1ll*(i-1)*(i);
        cout << tmp/(i-1)*tmp - cur/(i-1)<<endl;;
        cur = tmp;
    }
}
