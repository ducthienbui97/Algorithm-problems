#include <bits/stdc++.h>
using namespace std;
string to_string(int t){
    string s;
    s.push_back(t/10 + '0');
    s.push_back(t%10 + '0');
    return s;
}
int diff(string & a, string & b){
    int cnt =0;
    for(int i=0;i<5;i++)
        cnt += (a[i]!=b[i]);
    return cnt;
}
main(){
    int fm;
    int maxdiff = 10;
    string s;
    string ans;
    cin >> fm;
    cin >> s;

    for(int i = (fm==12); i < fm+(fm==12); i++)
    for(int j = 0; j < 60; j++){
        string f;
        f = to_string(i) + ":" + to_string(j);
        int dff = diff(s,f);
        if(maxdiff > dff){
            maxdiff = dff;
            ans = f;
        }
    }

    cout << ans;
}
