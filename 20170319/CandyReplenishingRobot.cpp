// https://www.hackerrank.com/contests/w30/challenges
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int t;
    cin >> n >> t;
    int ans = 0;
    vector<int> c(t);
    for(int c_i = 0; c_i < t; c_i++){
       cin >> c[c_i];
    }
    int remain = n;
    remain -= c[0];
    for(int i = 1; i < t;i++){
        if(remain < 5){
            ans += (n - remain);
            remain = n;
        }
        remain -= c[i];
    }
    cout << ans <<endl;
    return 0;
}
