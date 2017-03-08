#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    string s;
    set<string> ss;
    cin >> s;
    ss.insert(s);
    cin >> s;
    ss.insert(s);
    int n;
    cin >> n;
    cout <<*ss.begin() <<" "<<*ss.rbegin() <<endl;
    while(n-->0){
        cin >> s;
        ss.erase(s);
        cin >> s;
        ss.insert(s);
        cout <<*ss.begin() <<" "<<*ss.rbegin() <<endl;
    }
}
