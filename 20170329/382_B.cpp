//https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
#include <bits/stdc++.h>
using namespace  std;
bool prime(int n){
    int sq = sqrt(n);
    for(int i=2;i<=sq;i++)
        if(n%i==0) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if(prime(n)) cout << 1;
    else if(!(n%2)||prime(n-2)) cout << 2;
    else cout << 3;
}
