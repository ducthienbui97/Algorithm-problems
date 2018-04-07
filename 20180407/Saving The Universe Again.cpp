#include <bits/stdc++.h>
using namespace std;
int power(const string&s){
    int cur = 1;
    int dmg = 0;
    for(auto c:s){
        if(c=='S')
            dmg += cur;
        else cur*=2;
    }
    return dmg;
}
void solve(int test){
    int d;
    int h = 0;
    string s;
    cin >> d >> s;
    while(power(s) > d){
        bool done = false;
        for(int i = s.size() - 1; i > 0; i--)
        if(s[i-1] == 'C' && s[i] == 'S'){
            swap(s[i],s[i-1]);
            done = true;
            break;
        }
        if(!done) break;
        h++;
    }
    cout <<"Case #"<<test<<": "<< ((power(s) <= d)?to_string(h):"IMPOSSIBLE") << endl;
}
main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdtout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i <= t;i++)
        solve(i);
}
