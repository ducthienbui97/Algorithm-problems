#include <bits/stdc++.h>
using namespace std;
int n,m;
string sn,sm;
bool used[7];
int ans;
void bt(int it,string& s1,string& s2){
    if(it == sn.size()+sm.size()){
        ans += sn >= s1 && sm >= s2;
        return;
    }
    for(int i='0';i<'7';i++){
        if(used[i-'0']) continue;
        used[i-'0'] = true;
        if(it >= sn.size()) s2.push_back(i);
        else s1.push_back(i);
        bt(it+1,s1,s2);
        if(it >= sn.size()) s2.pop_back();
        else s1.pop_back();
        used[i-'0']=false;
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    n--;
    m--;
    while(n){
        sn.push_back(n%7+'0');
        n/=7;
    }
    reverse(sn.begin(),sn.end());
    if(!sn.size()) sn.push_back('0');
    while(m){
        sm.push_back(m%7+'0');
        m/=7;
    }
    reverse(sm.begin(),sm.end());
    if(!sm.size()) sm.push_back('0');
    string s1,s2;
    bt(0,s1,s2);
    cout << ans <<endl;
}
