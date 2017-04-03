#include <bits/stdc++.h>
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    int n,t;
    deque<int> s;
    string p;
    string ss;
    cin >> n >> t >>p;
    bool dec = false;
    for(int i=0; i<n; i++) {
        if(!dec)
            ss.push_back(p[i]);
        else if(p[i] < '5') s.push_back(p[i] - '0');
        else {
            s.push_back(p[i]-'0');
            break;
        }
        dec |= p[i] == '.';
    }
    int rem = 0;
    int tmp;
    while(t > 0 && !s.empty()) {
        tmp = rem + s.back();
        s.pop_back();
        if(tmp >= 5) {
            t--;
            rem = 1;
        } else {
            s.push_back(tmp);
            rem = 0;
            break;
        }
    }
    ss.pop_back();
    reverse(ss.begin(),ss.end());
    if(rem == 1)
        if(s.empty())
            for(int i=0; i<ss.size(); i++) {
                char c = rem + ss[i];
                if(c > '9')
                    ss[i] = '0',rem = 1;
                else
                    ss[i] = c,rem = 0;
            }
        else s.back()+=1,rem = 0;
    if(rem == 1) ss.push_back('1');
    reverse(ss.begin(),ss.end());
    if(!s.empty()) {
        ss.push_back('.');
        for(int i=0; i<s.size(); i++)
            ss.push_back(s[i]+'0');
    }
    cout <<ss <<endl;
}
