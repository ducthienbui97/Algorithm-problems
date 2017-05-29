#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto&u:v) cin >> u;
    int s1=0,s2=0;
    for(int i=0;i<n/2;i++)
        s1 += v[i];
    for(int i=n/2;i<n;i++)
        s2 += v[i];
    cout << abs(s1-s2) <<endl;
}
