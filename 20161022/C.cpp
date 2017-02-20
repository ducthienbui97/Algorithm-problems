#include<bits/stdc++.h>
using namespace std;
int lo[26];
bool F[26][26];
bool ck[26][26];
char C[2][27];
void rotate(string& s) {
    char c = s[0];
    for(int i = 0; i < s.size()-1; i++)
        s[i]=s[i+1];
    s[s.size()-1] = c;
    }
bool check(string& s) {
    for(int i = 0 ; i < 13; i++)
        C[0][i] = s[i];
    for(int i = 0 ; i < 13; i++)
        C[1][12-i] = s[i+13];
    memset(ck,0,sizeof ck);
    for(int i = 0; i < 13; i++) {
        if(i > 0) {
            ck[C[0][i]-'A'][C[0][i-1]-'A'] = true;
            ck[C[0][i]-'A'][C[1][i-1]-'A'] = true;
            ck[C[1][i]-'A'][C[1][i-1]-'A'] = true;
            ck[C[1][i]-'A'][C[0][i-1]-'A'] = true;
            }
        if(i < 12) {
            ck[C[0][i]-'A'][C[0][i+1]-'A'] = true;
            ck[C[0][i]-'A'][C[1][i+1]-'A'] = true;
            ck[C[1][i]-'A'][C[1][i+1]-'A'] = true;
            ck[C[1][i]-'A'][C[0][i+1]-'A'] = true;
            }
        ck[C[0][i]-'A'][C[1][i]-'A']=true;
        }
    for(int i = 0 ; i< 26; i++)
        for(int j = 0 ; j < 26; j++)
            if(F[i][j] && !(ck[i][j]||ck[j][i])){
            return false;
            }
    return true;
    }
main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    memset(lo,-1,sizeof lo);
    int x1,x2;
    for(int i = 0 ; i< s.size(); i++) {
        if(lo[s[i]-'A']>=0) {
            x1 = lo[s[i]-'A'];
            x2 = i;
            }
        else {
            lo[s[i]-'A'] = i;
            }
        if(i > 0) {
            F[s[i-1]-'A'][s[i]-'A'] = F[s[i]-'A'][s[i-1]-'A'] = true;
            }
        }
    if(x2-x1==1) {
        cout <<"Impossible";
        return 0;
        }
    string s1 = "";
    for(int i = 0 ; i < s.size(); i++)
        if(i!=x2) s1.push_back(s[i]);
    for(int i = 0 ; i < s.size(); i++) {
        rotate(s1);
        if(check(s1)) {
            cout << C[0]<<'\n'<<C[1]<<endl;
            return 0;
            }
        }
    cout <<"Impossible";

    }
