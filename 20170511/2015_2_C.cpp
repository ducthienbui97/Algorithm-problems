#include <bits/stdc++.h>
using namespace std;
double X,V;
int n;
int ans;
string S[22];
bool E[22];
unordered_set<string> eBase,fBase;
void check(){
    unordered_set<string> e,f;
    int cnt = 0;
    for(int i=2;i<n;i++){
        stringstream ss(S[i]);
        string s;
        while(ss >> s)
        if(E[i]){
            if(eBase.find(s) == eBase.end()) e.insert(s);
        }
        else {
            if(fBase.find(s) == fBase.end()) f.insert(s);
        }
    }
    for(auto&s:e) if(fBase.find(s) != fBase.end() || f.find(s) != f.end()) cnt ++;
    for(auto&s:f) if(eBase.find(s) != eBase.end()) cnt ++;
    ans = min(ans,cnt);
}
void bt(int t){
    if(t==n){
        check();
        return;
    }
    bt(t+1);
    E[t] = true;
    bt(t+1);
    E[t] = false;
}
void solve(int nTest){
    eBase.clear();
    fBase.clear();
    ans = 1<<30;
    cin >> n;
    getline(cin,S[0]);
    for(int i=0;i<n;i++){
        getline(cin,S[i]);
    }
    E[0] = 1;
    stringstream ss(S[0]);
    string s;
    while(ss >> s)eBase.insert(s);
    ss = stringstream(S[1]);
    int base = 0;
    while(ss >> s){
        fBase.insert(s);
    }
    for(s:fBase){
        if(eBase.find(s) != eBase.end()) base ++;
    }
    bt(2);
    if(ans == 1<<30) ans = 0;
    cerr <<nTest<<endl;
    cout <<"Case #"<<nTest<<": "<<base + ans<<endl;
}
main(){
    freopen("C-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}


