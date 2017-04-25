#include <bits/stdc++.h>
using namespace std;
string ans,cur;
int n;
string S = "ROYGBV";
int cnt[266];
string gen(int R,int B,int Y) {
    string rep;
    if(R<0||B<0||Y<0||R>B+Y||B>R+Y||Y>B+R) return "";
    if(R>0) rep = "R",R--;
    else if(B>0) rep = "B",B--;
    else if(Y>0) rep = "Y",Y--;
    while(R||B||Y)
        if(rep.back()=='R') {
            if(B > Y || (B==Y&&rep[0]=='B')) rep.push_back('B'),B--;
            else rep.push_back('Y'),Y--;
        } else if(rep.back()=='B') {
            if(R > Y || (R==Y&&rep[0]=='R')) rep.push_back('R'),R--;
            else rep.push_back('Y'),Y--;
        } else {
            if(B > R || (B==R&&rep[0]=='B')) rep.push_back('B'),B--;
            else rep.push_back('R'),R--;
        }
    return rep;
}
void solve(int nTest) {
    cin >> n;
    for(char c:S)
        cin >> cnt[c];
    ans = gen(cnt['R']-cnt['G'],cnt['B']-cnt['O'],cnt['Y']-cnt['V']);
    string sG,sO,sV;
    for(int i=0; i<cnt['G']; i++) sG+=("GR");
    for(int i=0; i<cnt['O']; i++) sO+=("OB");
    for(int i=0; i<cnt['V']; i++) sV+=("VY");
    if(ans.size()==0)
        if(cnt['G']+cnt['O']+cnt['V']!=max(cnt['G'],max(cnt['O'],cnt['V']))) ans = "";
        else ans = sG+sO+sV;
    else {
        for(int i=0; i<ans.size(); i++)
            if(ans[i] == 'R') {
                ans = ans.substr(0,i+1)+sG+ans.substr(i+1);
                break;
            }
        for(int i=0; i<ans.size(); i++)
            if(ans[i] == 'B') {
                ans = ans.substr(0,i+1)+sO+ans.substr(i+1);
                break;
            }
        for(int i=0; i<ans.size(); i++)
            if(ans[i] == 'Y') {
                ans = ans.substr(0,i+1)+sV+ans.substr(i+1);
                break;
            }

    }
    if(ans.size() != n) ans = "IMPOSSIBLE";
    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
main() {
    freopen("B-large-practice.in","r",stdin);
   freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

