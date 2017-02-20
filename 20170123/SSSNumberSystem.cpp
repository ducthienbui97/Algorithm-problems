#include<bits/stdc++.h>
using namespace std;
int get(char c){
    if(c >= 'A') return c-'A'+10;
    else return c-'0';
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        int Min = 1;
        int S = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            S+=get(s[i]);
            Min = max(Min,get(s[i]));
        }
        for(;Min < 36; Min++){
            if(S%Min==0){
                ans = Min+1;
                break;
            }
        }
        if(!ans) cout << "No solution.\n";
        else cout << ans << '\n';
    }
}
