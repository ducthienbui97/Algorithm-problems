#include <bits/stdc++.h>
using namespace std;
void solve(int t) {

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto&u:v)
        cin >> u;
    cout << "Case #" << t << ": ";
    if(v[0] == 0 || v.back() == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        v[0] --;
        v.back() -- ;
        int xx = 0;
        vector<pair<int,int> > ans;
        for(int i = 1; i + 1 < n; i++)
            for(int j = 0; j < n; j ++)
                if(v[j]) {
                    ans.emplace_back(i,j);
                    v[j] --;
                    xx = max(xx, abs(i - j));
                    break;
                }
        vector<string> out(xx + 1, string(n,'.'));
        for(auto&p:ans) {
            if(p.first > p.second)
                for(int idx = 0; p.first - idx > p.second; idx ++)
                    out[idx][p.first - idx] = '/';
            else if(p.first < p.second)
                for(int idx = 0; p.first + idx < p.second; idx ++)
                    out[idx][p.first + idx] = '\\';
        }
        cout << out.size() << endl;
        for(auto&s:out)
            cout << s << endl;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}
