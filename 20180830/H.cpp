#include <bits/stdc++.h>

using namespace std;
void handle(deque<char> &d, string& s){
    if(s.size() == 0)
        return;
    if(s.size() % 2 == 0){
        d.push_front(s.back());
    }
    else {
        d.push_back(s.back());
    }
    s.pop_back();
    handle(d,s);
}
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        string s;
        cin >> n;
        getline(cin,s);
        getline(cin,s);
        deque<char> d;
        reverse(s.begin(),s.end());
        handle(d,s);
        string ans;
        for(char c: d)
            ans.push_back(c);
        cout << ans << endl;
    }
}


