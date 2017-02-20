#include <bits/stdc++.h>
using namespace std;
void doit(int num){
    int n;
    string s;
    string ans;
    int MAX = 0;
    cin >> n;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        set<char> ms;
        for(int j=0;j<s.size();j++)
            if(s[j] >= 'A' && s[j] <= 'Z') ms.insert(s[j]);
        if(ms.size() > MAX){
            ans = s;
            MAX = ms.size();
        }
        else if(ms.size() == MAX)
            ans = min(ans,s);
    }
    cout <<"Case #"<<num<<": "<<ans<<endl;
}
main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int c = 1;c <= t;c++) doit(c);
}
