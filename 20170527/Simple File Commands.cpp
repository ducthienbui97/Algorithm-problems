#include <bits/stdc++.h>
using namespace std;
unordered_map<long long,set<int> > mp;
int crt(string& s){
    long long hs = 0;
    for(int i=0;i<s.size();i++)
        hs = hs*27 + s[i] - 'a' + 1;
    if(mp.find(hs) == mp.end())
        mp[hs].insert(0);
    int idx = *mp[hs].begin();
    mp[hs].erase(idx);
    if(!mp[hs].size()) mp[hs].insert(idx+1);
    return idx;
}
void del(string& s){
    long long hs = 0;
    int st = s.size();
    int idx = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(') st = i;
        if(i < st)
            hs = hs*27 + s[i] - 'a' + 1;
        if(i > st && s[i] != ')')
            idx = idx*10 + s[i] - '0';
    }
    mp[hs].insert(idx);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s,t;
        cin >> s;
        if(s[0] == 'c'){
            cin >> t;
            int idx = crt(t);
            cout << "+ "<<t;
            if(idx) cout <<'('<<idx<<')';
        }else if(s[0] == 'd'){
            cin >> t;
            del(t);
            cout << "- "<<t;
        }else{
            cin >> t;
            del(t);
            cout <<"r "<<t<<" -> ";
            cin >> t;
            int idx = crt(t);
            cout << t;
            if(idx) cout <<'('<<idx<<')';
        }
        cout <<'\n';
    }
}
