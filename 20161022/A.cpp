#include<bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n && s[i]=='<';i++,cnt++);
    for(int i = n-1; i >=0 && s[i]=='>';i--,cnt++);
    cout << cnt <<endl;
}
