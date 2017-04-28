#include <bits/stdc++.h>
using namespace std;
int cal(string& s){
    set<char> ms;
    for(char c:s){
        if(c >= 'A' && c <= 'Z') ms.insert(c);
    }
    return ms.size();
}
void solve(int nTest){
    string ans;
    string s;
    int n;
    cin >> n;
    getline(cin,ans);
    for(int i=0;i<n;i++){
        getline(cin,s);
        if(cal(s) > cal(ans)) ans = s;
        else if(cal(s) == cal(ans) && s < ans) ans = s;
    }
    cout <<"Case #"<<nTest<<": "<<ans<<endl;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)solve(i);
}
