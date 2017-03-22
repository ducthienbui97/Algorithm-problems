#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    for(auto&u:v) cin >> u;
    int Min = *min_element(v.begin(),v.end());
    int Max = *max_element(v.begin(),v.end());
    for(auto&u:v) n-=(u==Min || u==Max);
    cout << n <<endl;
}
