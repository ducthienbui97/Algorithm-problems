#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6+10;
int last[maxN][26];
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i <26; i++)
        last[0][i] = -1;
    last[0][s[0] - 'a'] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 26; j++)
            last[i][j] = last[i-1][j];
        last[i][s[i] - 'a'] = i;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> s;
        int ans = 0;
        int tmp = n - 1;
        while(ans < s.size() && tmp >= 0){
            if(last[tmp][s[s.size()-ans-1]- 'a'] < 0)
                break;
            tmp = last[tmp][s[s.size()-ans-1]- 'a'] - 1;
            ans ++;
        }
        cout << ans << endl;
    }
}

