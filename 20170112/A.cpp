#include <bits/stdc++.h>
using namespace std;
int cons[555];
int cont[555];
main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string t = "Bulbasaur";
    for(int i=0;i<s.size();i++)
        cons[s[i]] ++;
    for(int i=0;i<t.size();i++)
        cont[t[i]] ++;
    int ans = 1<<30;
    for(int i=0;i<t.size();i++){
        ans = min(ans,cons[t[i]]/cont[t[i]]);
    }
    cout << ans <<endl;
}
