#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > vc;
vector<string> vs;
int counter[1111111][26];
unordered_set<int> lo[26];
const long long oneB = 1e9;
void solve(int t) {
    int n;
    cin >> n;
    vs.resize(n);
    vc.resize(n);
    for(int  i = 0; i < 26; i++){
        lo[i].clear();
        counter[1][i] = 0;
        counter[2][i] = 0;
    }
    for(int  i = 0; i < n; i++){
        unordered_map<char,int> cnt;
        cin >> vs[i];
        vc[i].clear();
        for(auto&c: vs[i]) cnt[c]++;
        for(auto&it:cnt) vc[i].emplace_back(it.first-'a',it.second);
    }
    int sz = 0;
    char s1,s2;
    long long a,b,c,d,l;
    cin >> s1 >> s2 >> l >> a >> b >> c >> d;
    int x1 = s1,x2 = s2;
    //unordered_set<long long> encountered;
    //encountered.insert(oneB*((int)s1) + (int)s2);
    lo[s1 - 'a'].insert(1);
    lo[s2 - 'a'].insert(2);
    counter[1][s1 - 'a'] = 1;
    counter[2][s1 - 'a'] = 1;
    counter[2][s2 - 'a'] = 1 + (s1 == s2);
    for(int i = 3; i <= l; i++){
        long long x = ((a*x2 + b*x1)%d + c)%d;
        char s = (x%26) + 'a';
        lo[s - 'a'].insert(i);
        for(int ii = 0; ii < 26; ii++)
            counter[i][ii] = counter[i - 1][ii];
        counter[i][s - 'a'] ++;
        x1 = x2;
        x2 = x;
        long long tmp = oneB*x1 + x2;
       // if(encountered.find(tmp) != encountered.end())
        //    break;
        //encountered.insert(tmp);
        //cout << s;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int st:lo[vs[i][0]-'a']){
            int ed = (st + vs[i].size() - 1);
            if(lo[vs[i].back() - 'a'].find(ed) != lo[vs[i].back() - 'a'].end()){
                bool ok = true;
                for(auto&p:vc[i]){
                    if(counter[ed][p.first] - counter[st - 1][p.first] != p.second)
                        ok = false;
                }
                if(ok){
                    ans ++;
                    break;
                }
            }

        }
    }
    cout <<"Case #" <<t <<": " <<  ans<< endl;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++)
        solve(i);
}
