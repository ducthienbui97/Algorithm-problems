#include <bits/stdc++.h>

using namespace std;
priority_queue<pair<int,int>> pr;

main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++) {
        unordered_map <char,int> mp;
        string s;
        cin >> s;
        int n;
        cin >> n;
        for(char c:s)
            mp[c]++;
        for(auto it:mp)
            pr.push({0,it.second});
        int ans = 0;
        while(!pr.empty()) {
            while(!pr.empty() && -pr.top().first < ans){
                auto x = pr.top();
                pr.pop();
                x.first = -ans;
                pr.push(x);
            }
            auto x = pr.top();
            pr.pop();
            if(!x.second)
                continue;
            ans = max(ans + 1,-x.first + 1);
            pr.push({-(ans + n), x.second - 1});
        }
        cout << ans << endl;
    }
}



